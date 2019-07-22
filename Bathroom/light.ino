/*

Код для ардуино, управляющей светодиодным светильником
По короткому нажатию кнопки включает и выключает питание, длинное нажатие плавно изменяет яркость
Первое длинное нажатие увеличивает яркость, дальше уменьшают/увеличивают через одно
Значение яркости сохраняется в памяти, так что при следующем включении настроенный уровень яркости сохранится 

*/

// пин с кнопкой, подтянут вниз
#define BUTTON_PIN 2
// пин on на материнке
#define ON_PIN 4
// пин dim на материнке
#define DIM_PIN 3

#define DECREASE 0
#define INCREASE 1
#define OFF 0
#define ON 1
#define FALSE 0
#define TRUE 1

// Граничные значения яркости
const unsigned char minBrightnessLevel = 20;
const unsigned char maxBrightnessLevel = 255;

// Делей между сменой состояния на входе BUTTON_PIN и принятием решения о смене состояния кнопки
const unsigned long int stateChangeDelay = 5;
// Время короткого (для включения) и длинного (для изменения яркости) нажатия
const unsigned long int shortPressTime = 80;
const unsigned long int longPressTime = 1500;
// Задержка между тиками при изменении яркости
// весь диапазон пройдёт за (maxBrightnessLevel-minBrightnessLevel)*brightnessChangeTickTime мс
const unsigned long int brightnessChangeTickTime = 20;

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

// момент последнего тика изменения яркости
unsigned long int lastTickTime = 0;
// моменты логического нажатия и отпускания кнопки
unsigned long int pressTime = 0;
unsigned long int releaseTime = 0;

// состояние светодиода
boolean ledState = OFF;
// текущая яркость
unsigned char ledBrightness = minBrightnessLevel;

void setup() {
	pinMode(BUTTON_PIN, INPUT);
	pinMode(ON_PIN, OUTPUT);
	attachInterrupt( digitalPinToInterrupt( BUTTON_PIN ), button_edge_detected, CHANGE);
}

void loop() {
	
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
	// то яркость изменится на +-1 в замисти от запланированного действия
	if ( pressedFlag == ON ) {
		if ( ( millis() - pressTime ) >= longPressTime ) {
			ledState = ON;
			if ( ( millis() - lastTickTime ) >= brightnessChangeTickTime ) {
				if ( brightnessAction == INCREASE) {
					if ( ledBrightness < maxBrightnessLevel ) ++ledBrightness;
				} else {
					if ( ledBrightness > minBrightnessLevel ) --ledBrightness;
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
				ledState = !ledState;
			} else {
				// если кнопка была нажата дольше чем время короткого нажатия,
				// и отжата позже начала настройки яркости, то поменяется запланированное действие по изменению яркости
				brightnessAction = !brightnessAction;
			}
		}
		releasedFlag = OFF;
	}
	
	digitalWrite( ON_PIN, ledState );
	analogWrite( DIM_PIN, ledBrightness );

}


// обработка еджа на входе
void button_edge_detected() {

	if ( buttonState == digitalRead( BUTTON_PIN ) ) {
		difference = FALSE;
	} else {
		difference = TRUE;
	}
	
	edgeTime = millis();

}
