#include <Servo.h> //library needed to control servo

//defining pin numbers in global space
#define motorPin 3
#define pot A0

//declaring variables for potentiometer position, servo motor input signal, input voltage
int potPos, servoSignal;
float inputVoltage;

//declaring servoMotor object of class Servo (from servo.h)
Servo servoMotor;

void setup() {
  //starting serial communication
  Serial.begin(9600);
  //printing header for output table
  Serial.println("Volt(in), servoAngle");

  //setting output pin for servo input
  pinMode(motorPin, OUTPUT);

  //setting input pin for potentiometer
  pinMode(pot, INPUT);

  servoMotor.attach(motorPin);
}

void loop() {
  //reading potentiometer value
  potPos = analogRead(pot);
  //mapping 10bit analog input value to analog output value, servo angle increases 
  //with analog signal increase
  servoSignal = map(potPos, 0, 1023, 20, 130);

  //setting servo angle
  servoMotor.write(servoSignal);

  //printing needed table values
  inputVoltage = potPos * (5.0 / 1023.0);
  Serial.print(inputVoltage);
  Serial.print(", ");
  Serial.println(servoSignal);
}
