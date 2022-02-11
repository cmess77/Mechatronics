#include <Servo.h>

//defining pin numbers in global space
#define motorPin 3
#define potentiometer A0

#define servoLowerLimit 20
#define servoUpperLimit 130

//declaring variables for potentiometer position, servo motor input signal, input voltage
int potentiometerPosition, servoAngle;
float inputVoltage;

Servo servoMotor;


void setup() {
  //starting serial communication
  Serial.begin(9600);
  //printing header for output table
  Serial.println("Volt(in), servoAngle");

  //setting output pin for servo input
  pinMode(motorPin, OUTPUT);

  //setting input pin for potentiometer
  pinMode(potentiometer, INPUT);

  //attaching servoMotor object to motorPin
  servoMotor.attach(motorPin);
}


void loop() {
  //reading potentiometer value
  potentiometerPosition = analogRead(potentiometer);
  
  //mapping 10bit analog input value to analog output value, servo angle increases 
  //with analog signal increase
  servoAngle = map(potentiometerPosition, 0, 1023, servoLowerLimit, servoUpperLimit);

  //moving servoMotor to servoAngle position
  servoMotor.write(servoAngle);

  //calculating input voltage from analog signal
  inputVoltage = potentiometerPosition * (5.0/1023.0);

  //printing needed table values
  Serial.print(inputVoltage);
  Serial.print(", ");
  Serial.println(servoAngle);
}
