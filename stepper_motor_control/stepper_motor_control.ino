#define pot A0
#define in1 7
#define in2 6
#define in3 5
#define in4 4

int potPos, delayTime;

void setup(void) {
  Serial.begin(9600);
  Serial.println("PotPos, delayTime");
  pinMode(pot, INPUT);
  
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}


void loop(void) {
 while((potPos = analogRead(pot)) <= 512) {
  delayTime = map(potPos, 0, 512, 800,10000);
  reverseDrive(delayTime);

  Serial.print(potPos);
  Serial.print(", ");
  Serial.println(delayTime);
 }

 while((potPos = analogRead(pot)) > 512) {
  delayTime = map(potPos, 513, 1023, 10000,800);
  forwardDrive(delayTime);

  Serial.print(potPos);
  Serial.print(", ");
  Serial.println(delayTime);
  }
}


void pinWrite(int pin1,int pin2,int pin3,int pin4) {
  digitalWrite(in1,pin1);
  digitalWrite(in2,pin2);
  digitalWrite(in3,pin3);
  digitalWrite(in4,pin4);
}


void reverseDrive(int us){
  pinWrite(1,0,0,0);
  delayMicroseconds(us);
  pinWrite(1,1,0,0);
  delayMicroseconds(us);
  pinWrite(0,1,0,0);
  delayMicroseconds(us);
  pinWrite(0,1,1,0);
  delayMicroseconds(us);
  pinWrite(0,0,1,0);
  delayMicroseconds(us);
  pinWrite(0,0,1,1);
  delayMicroseconds(us);
  pinWrite(0,0,0,1);
  delayMicroseconds(us);
  pinWrite(1,0,0,1);
  delayMicroseconds(us);
}


void forwardDrive(int us){
  pinWrite(0,0,0,1);
  delayMicroseconds(us);
  pinWrite(0,0,0,1);
  delayMicroseconds(us);
  pinWrite(0,0,1,1);
  delayMicroseconds(us);
  pinWrite(0,0,1,0);
  delayMicroseconds(us);
  pinWrite(0,1,1,0);
  delayMicroseconds(us);
  pinWrite(0,1,0,0);
  delayMicroseconds(us);
  pinWrite(1,1,0,0);
  delayMicroseconds(us);
  pinWrite(1,0,0,1);
  delayMicroseconds(us);
}
