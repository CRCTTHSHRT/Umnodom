/*

��� ��� �������, ����������� ������������ ������������
�� ��������� ������� ������ �������� � ��������� �������, ������� ������� ������ �������� �������
������ ������� ������� ����������� �������, ������ ���������/����������� ����� ����
�������� ������� ����������� � ������, ��� ��� ��� ��������� ��������� ����������� ������� ������� ���������� 

*/

// ��� � �������, �������� ����
#define BUTTON_PIN 2
// ��� on �� ���������
#define ON_PIN 4
// ��� dim �� ���������
#define DIM_PIN 3

#define DECREASE 0
#define INCREASE 1
#define OFF 0
#define ON 1
#define FALSE 0
#define TRUE 1

// ��������� �������� �������
const unsigned char minBrightnessLevel = 20;
const unsigned char maxBrightnessLevel = 255;

// ����� ����� ������ ��������� �� ����� BUTTON_PIN � ��������� ������� � ����� ��������� ������
const unsigned long int stateChangeDelay = 5;
// ����� ��������� (��� ���������) � �������� (��� ��������� �������) �������
const unsigned long int shortPressTime = 80;
const unsigned long int longPressTime = 1500;
// �������� ����� ������ ��� ��������� �������
// ���� �������� ������ �� (maxBrightnessLevel-minBrightnessLevel)*brightnessChangeTickTime ��
const unsigned long int brightnessChangeTickTime = 20;

// ���� 1, �� ������ �� ����� �� ������������� ����������� ��������� ������
volatile boolean difference = FALSE;
// ������ ���������� ����������
volatile unsigned long int edgeTime = 0;
// ���������� ��������� ������
boolean buttonState = OFF;

// ����� ��������������� ������� � ����������
boolean pressedFlag = OFF;
boolean releasedFlag = OFF;

// ��������� �������� �� ��������� �������
boolean brightnessAction = INCREASE;

// ������ ���������� ���� ��������� �������
unsigned long int lastTickTime = 0;
// ������� ����������� ������� � ���������� ������
unsigned long int pressTime = 0;
unsigned long int releaseTime = 0;

// ��������� ����������
boolean ledState = OFF;
// ������� �������
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
	
	
	// ��������� �������, ���� ������ ������ �����, � ������ ���������� ������� � �������� ����
	// �� ������� ��������� �� +-1 � ������� �� ���������������� ��������
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
	
	// ��������� ���������� ������
	if ( releasedFlag == ON ) {
		if ( ( releaseTime - pressTime ) >= shortPressTime ) {
			// ���� ������ ���� ������ ������ ��� ����� ��������� �������,
			// � ������ ������ ������ ��������� �������, �� ���������� ��������� �����������
			if ( ( releaseTime - pressTime ) < longPressTime ) {
				ledState = !ledState;
			} else {
				// ���� ������ ���� ������ ������ ��� ����� ��������� �������,
				// � ������ ����� ������ ��������� �������, �� ���������� ��������������� �������� �� ��������� �������
				brightnessAction = !brightnessAction;
			}
		}
		releasedFlag = OFF;
	}
	
	digitalWrite( ON_PIN, ledState );
	analogWrite( DIM_PIN, ledBrightness );

}


// ��������� ���� �� �����
void button_edge_detected() {

	if ( buttonState == digitalRead( BUTTON_PIN ) ) {
		difference = FALSE;
	} else {
		difference = TRUE;
	}
	
	edgeTime = millis();

}
