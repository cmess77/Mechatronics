//included in order to pacify VSCode lol
#include <Arduino.h>

//defining pin numbers in global space
#define motorEnable 10
#define input1 12
#define input2 13
#define potentiometer A0

//declaring variables for potentiometer position, motor speed input signal
int potentiometerPosition, dcMotorSignal;
float inputVoltage;
float dutyCyclePercent;

void setup() {
  //starting serial communication
  Serial.begin(9600);
  //printing header for output table
  Serial.println("V(in), Output");

  //setting output pins for enable, in1 and in2 pins on L293D
  pinMode(motorEnable, OUTPUT);
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);

  //setting input pin for potentiometer
  pinMode(potentiometer, INPUT);
}

void loop() {
  //reading pot position using analog input signal
  potentiometerPosition = analogRead(potentiometer);

  //case 1: pot in lower half, motor running counterclockwise
  if(potentiometerPosition <= 512) {
    //mapping 10bit analog input value to analog out value, PWM decreases with analog signal increase
    dcMotorSignal = map(potentiometerPosition, 0, 512, 255, 0);

    //setting enable pin to PWM signal from dcMotorSignal, and writing in1 HIGH and in2 LOW (counterclockwise)
    analogWrite(motorEnable, dcMotorSignal);
    digitalWrite(input1, LOW);
    digitalWrite(input2, HIGH);

    //calculating input voltage from analog signal
    inputVoltage = potentiometerPosition * (5.0/1023.0);
    //calculating duty cycle (out of 100%) from dcMotorSignal
    dutyCyclePercent = dcMotorSignal * (100.0/255.0);

    //printing needed table values
    Serial.print(inputVoltage);
    Serial.print(", ");
    Serial.println(dutyCyclePercent);
  }

  //case 2: pot in upper half, motor running clockwise
  else if(potentiometerPosition > 512) {
    //mapping 10bit analog value to analog out value, PWM increases with analog signal increase
    dcMotorSignal = map(potentiometerPosition, 513, 1023, 0, 255);

    //setting enable pin to PWM signal from dcMotorSignal, and writing in1 LOW and in2 HIGH 
    analogWrite(motorEnable, dcMotorSignal);
    digitalWrite(input1, HIGH);
    digitalWrite(input2, LOW);

    //calculating input voltage from analog signal
    inputVoltage = potentiometerPosition * (5.0/1023.0);
    //calculating duty cycle (out of 100%) from dcMotorSignal
    dutyCyclePercent = dcMotorSignal * (100.0/255.0);

    //printing needed table values
    Serial.print(inputVoltage);
    Serial.print(", ");
    Serial.println(dutyCyclePercent);
  }

}
