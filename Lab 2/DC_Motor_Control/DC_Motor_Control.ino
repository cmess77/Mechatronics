//defining pin numbers in global space
#define motorEnable 10
#define input1 12
#define input2 13
#define pot A0

//declaring variables for potentiometer position, motor speed input signal
int potPos, dcInput;
float inputVoltage;

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
  pinMode(pot, INPUT);
}

void loop() {
  //reading pot position using analog input signal
  potPos = analogRead(pot);

  //case 1: pot in lower half, motor running counterclockwise
  if(potPos <= 512) {
    //mapping 10bit analog input value to analog out value, PWM decreases with analog signal increase
    dcInput = map(potPos, 0, 512, 255, 0);

    //setting enable pin to PWM signal from dcInput, and writing in1 HIGH and in2 LOW (counterclockwise)
    analogWrite(motorEnable, dcInput);
    digitalWrite(input1, LOW);
    digitalWrite(input2, HIGH);

    //printing needed table values
    float inputVoltage = potPos * (5.0 / 1023.0);
    Serial.print(inputVoltage);
    Serial.print(", ");
    Serial.println(dcInput);
  }

  //case 2: pot in upper half, motor running clockwise
  else if(potPos > 512) {
    //mapping 10bit analog value to analog out value, PWM increases with analog signal increase
    dcInput = map(potPos, 513, 1023, 0, 255);

    //setting enable pin to PWM signal from dcInput, and writing in1 LOW and in2 HIGH 
    analogWrite(motorEnable, dcInput);
    digitalWrite(input1, HIGH);
    digitalWrite(input2, LOW);

    //printing needed table values
    float inputVoltage = potPos * (5.0 / 1023.0);
    Serial.print(inputVoltage);
    Serial.print(", ");
    Serial.println(dcInput);
  }

}
