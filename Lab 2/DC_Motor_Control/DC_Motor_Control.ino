#define motorEnable 10
#define input1 12
#define input2 13
#define pot A0

int potPos, dcInput;

void setup() {
  Serial.begin(9600);
  pinMode(motorEnable, OUTPUT);
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
  pinMode(pot, INPUT);
}

void loop() {
 potPos = analogRead(pot);

 if(potPos <= 512) {
  dcInput = map(potPos, 0, 512, 255, 0);
  analogWrite(motorEnable, dcInput);
  digitalWrite(input1, LOW);
  digitalWrite(input2, HIGH);
 }

 else if(potPos > 512) {
  dcInput = map(potPos, 513, 1023, 0, 255);
  analogWrite(motorEnable, dcInput);
  digitalWrite(input1, HIGH);
  digitalWrite(input2, LOW);
 }

}
