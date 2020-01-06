/*

Код для ардуино, управляющей светодиодным светильником
По короткому нажатию кнопки включает и выключает питание, длинное нажатие плавно изменяет яркость
Первое длинное нажатие увеличивает яркость, дальше уменьшают/увеличивают через одно
Значение яркости сохраняется в памяти, так что при следующем включении настроенный уровень яркости сохранится 

*/
#include <FastLED.h>
#include <avr/wdt.h>

#define NUM_STRIPS 3
#define NUM_LEDS_PER_STRIP 150

// устанавливаем таймер watchdog timeout
#define WDTO_DEFAULT WDTO_4S

// пин с кнопкой, подтянут вниз
#define BUTTON_PIN 3

#define DECREASE 0
#define INCREASE 1
#define OFF 0
#define ON 1
#define FALSE 0
#define TRUE 1

// инвертируем значение уровня яркости, чтобы получить требуемый уровень ШИМ
#define BR_LEVEL_TO_PWM(level) ( 255 - level )

CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];

//const int STRIP_PIN[3] = {10, 11, 12};

// Граничные значения яркости
const unsigned char minBrightnessLevel = 0;
const unsigned char maxBrightnessLevel = 255;

// Делей между сменой состояния на входе BUTTON_PIN и принятием решения о смене состояния кнопки
const unsigned long int stateChangeDelay = 5;
// Время короткого (для включения) и длинного (для изменения яркости) нажатия
const unsigned long int shortPressTime = 80;
const unsigned long int longPressTime = 1500;
// Задержка между тиками при изменении яркости
// весь диапазон пройдёт за (maxBrightnessLevel-minBrightnessLevel)*brightnessChangeTickTime мс
const unsigned long int brightnessChangeTickTime = 5;
// Задержка между изменением уставки яркости
const unsigned long int brightnessSetTickTime = 20;

// если 1, то сигнал на входе не соответствует логическому состоянию кнопки
volatile boolean difference = FALSE;
// момент последнего прерывания
volatile unsigned long int edgeTime = 0;
// логическое состояние кнопки
boolean buttonState = OFF;

// Флаги необработанного нажатия и отпускания
boolean pressedFlag = OFF;
boolean releasedFlag = OFF;

// Следующее действие по изменению яркости
boolean brightnessAction = INCREASE;

// момент последнего тика изменения уставки яркости
unsigned long int lastTickTime = 0;
// момент последнего тика изменения ШИМ
unsigned long int lastStepTime = 0;
// моменты логического нажатия и отпускания кнопки
unsigned long int pressTime = 0;
unsigned long int releaseTime = 0;

// уровень яркости, в который светильник включится первый раз
unsigned char savedLedBrightness = minBrightnessLevel + 1;

// состояние светодиода
boolean ledState = OFF;
// текущая яркость
unsigned char ledBrightness = minBrightnessLevel;
unsigned char outputLevel = minBrightnessLevel;

void setup() {
    wdt_reset();
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    FastLED.addLeds<NEOPIXEL, 4>(leds[0], NUM_LEDS_PER_STRIP);
    FastLED.addLeds<NEOPIXEL, 5>(leds[1], NUM_LEDS_PER_STRIP);
    FastLED.addLeds<NEOPIXEL, 6>(leds[2], NUM_LEDS_PER_STRIP);
    attachInterrupt( digitalPinToInterrupt( BUTTON_PIN ), button_edge_detected, CHANGE);
    wdt_enable(WDTO_DEFAULT);
}

void loop() {

    wdt_reset();

    // управление светильником
    if ( millis() - lastStepTime >= brightnessChangeTickTime ) {
        lastStepTime = millis();
        if ( outputLevel < ledBrightness ) {
            outputLevel++;
        } else if ( outputLevel > ledBrightness ) {
            outputLevel--;
        }
        for (int i=0;i<NUM_STRIPS;i++) {
          for (int j=0;j<NUM_LEDS_PER_STRIP;j++) {
            leds[i][j].setHSV(0, 0, outputLevel);
          }
        }
        FastLED.show();
    }
    
    // устранение шума от контакта кнопки
    if ( difference == TRUE ) {
        if ( ( millis() - edgeTime ) >= stateChangeDelay ) {
            buttonState = !buttonState;
            difference = FALSE;
            if ( buttonState ) {
                pressTime = millis();
                pressedFlag = ON;
                releasedFlag = OFF;
            } else {
                releaseTime = millis();
                pressedFlag = OFF;
                releasedFlag = ON;
            }
        }
    }

    // изменения яркости, если кнопка нажата долго, и прошло достаточно времени с прошлого тика
    // то яркость изменится на +-1 в зависимости от запланированного действия
    if ( pressedFlag == ON ) {
        if ( ( millis() - pressTime ) >= longPressTime ) {
            if ( ledState == OFF ) {
                ledState = ON;
                ledBrightness = savedLedBrightness;
            }
            if ( ( millis() - lastTickTime ) >= brightnessSetTickTime ) {
                if ( brightnessAction == INCREASE) {
                    if ( ledBrightness < maxBrightnessLevel ) ledBrightness++;
                } else {
                    if ( ledBrightness > minBrightnessLevel+1 ) ledBrightness--;
                }
                lastTickTime = millis();
            }
        }
    }

    // обработка отпускания кнопки
    if ( releasedFlag == ON ) {
        if ( ( releaseTime - pressTime ) >= shortPressTime ) {
            // если кнопка была нажата дольше чем время короткого нажатия,
            // и отжата раньше начала настройки яркости, то поменяется состояние светильника
            if ( ( releaseTime - pressTime ) < longPressTime ) {
                // если светильник выключился, то сохраним значение последней яркости и потушим свет
                // если светильник включился, то восстановим сохранённое значение яркости
                if ( ledState == ON ) {
                    ledState = OFF;
                    savedLedBrightness = ledBrightness;
                    ledBrightness = minBrightnessLevel;
                } else {
                    ledState = ON;
                    ledBrightness = savedLedBrightness;
                }
            } else {
                // если кнопка была нажата дольше чем время короткого нажатия,
                // и отжата позже начала настройки яркости, то поменяется запланированное действие по изменению яркости
                brightnessAction = !brightnessAction;
            }
        }
        releasedFlag = OFF;
    }

}

// обработка еджа на входе
void button_edge_detected() {

    if ( buttonState != digitalRead( BUTTON_PIN ) ) {
        difference = FALSE;
    } else {
        difference = TRUE;
    }
    
    edgeTime = millis();

}
