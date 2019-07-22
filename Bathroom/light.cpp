#define BUTTON_PIN 2
#define ON_PIN 3
#define DIM_PIN 4


#define DECREASE 0
#define INCREASE 1

#define OFF 0
#define ON 1

#define FALSE 0
#define TRUE 1

const unsigned long int stateChangeDelay = 60;
const unsigned long int shortPressTime = 500;
const unsigned long int longPressTime = 3000;
const unsigned long int brightnessChangeTickTime = 10;

const unsigned char minBrightnessLevel = 20;
const unsigned char maxBrightnessLevel = 255;

volatile boolean buttonState = 0;
volatile boolean difference = 0;

volatile unsigned long int edgeTime = 0;
unsigned long int lastTickTime = 0;

boolean ledState = 0;
unsigned char ledBrightness = 255;

void setup() {
	attachInterrupt( 0, button_edge_detected, CHANGE);
	pinMode(BUTTON_PIN, INPUT);
	pinMode(ON_PIN, OUTPUT);
	pinMode(DIM_PIN, OUTPUT);
}

void loop() {
	
	if ( difference ) {
		if ( ( millis() - edgeTime ) >= stateChangeDelay ) {
			buttonState = !buttonState;
			if ( buttonState ) {
				unsigned long int pressTime = millis();
				boolean pressedFlag = ON;
				boolean releasedFlag = OFF;
			} else {
				unsigned long int releaseTime = millis();
				boolean pressedFlag = OFF;
				boolean releasedFlag = ON;
			}
		}
	}
	
	if ( pressedFlag ) {
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
	
	if ( releasedFlag ) {
		if ( ( releaseTime - pressTime ) >= shortPressTime && ( releaseTime - pressTime ) < longPressTime ) {
			ledState = !ledState;
			brightnessAction = !brightnessAction;
		}
		releasedFlag = OFF;
	}
	
	digitalWrite( ON_PIN, ledState );
	analogWrite( DIM_PIN, ledBrightness );
}

void button_edge_detected() {

	if ( buttonState == digitalRead( BUTTON_PIN ) ) {
		difference = TRUE;
	} else {
		difference = FALSE;
	}
	
	edgeTime = millis();

}
