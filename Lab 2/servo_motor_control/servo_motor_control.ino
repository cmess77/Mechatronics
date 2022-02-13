//included in order to pacify VSCode lol
#include <Arduino.h>

//defining pin numbers in global space
#define motorPin 3
#define potentiometer A0

//declaring variables for potentiometer position, input voltage, and servo angle
int potentiometerPosition;
float inputVoltage, servoAngle;

/*
minimum servo duty cycle; the servo doesn't actually respond under ~17% duty cycle, but 11% duty cycle 
*technically* corresponds to 20 degrees. 
*/
float servoLowerDutyCycle = 0.11;

//maximum servo duty cycle, given by 130/180
float servoUpperDutyCycle = 0.72;

//these are the values I'll map potentiometerPosition to
int servoLowerSignal = servoLowerDutyCycle * 255;
int servoUpperSignal = servoUpperDutyCycle * 255;

//signal to be sent to the servo motor
int motorSignal;


void setup() {
  //starting serial communication
  Serial.begin(9600);

  //setting output pin for servo input
  pinMode(motorPin, OUTPUT);

  //setting input pin for potentiometer
  pinMode(potentiometer, INPUT);
}


void loop() {
  //reading potentiometer value
  potentiometerPosition = analogRead(potentiometer);

  //mapping potentiometerPosition values to upper and lower motorSignal bounds
  motorSignal = map(potentiometerPosition, 0, 1023, servoLowerSignal, servoUpperSignal);

  //sending motorSignal to the servo in order to move it
  analogWrite(motorPin, motorSignal);

  //calculating input voltage from analog signal
  inputVoltage = potentiometerPosition * (5.0/1023.0);

  //calculating servo angle from Angle/PWM Signal ratio
  servoAngle = motorSignal * (180.0/255.0);

  //printing needed table values
  Serial.print(inputVoltage);
  Serial.print(", ");
  Serial.println(servoAngle);
}
