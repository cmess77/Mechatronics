//defining pin numbers in global space
#define pot A0
#define in1 7
#define in2 6
#define in3 5
#define in4 4

//declaring variables for potentiometer position, stepper motor step-delay
int potPos, delayTime;
float inputVoltage;

void setup(void) {
  //starting serial communication
  Serial.begin(9600);
  //printing header for output table
  Serial.println("PotPos, delayTime");

  //setting input pin for potentiometer
  pinMode(pot, INPUT);

  //setting output pins for coil1, coil2, coil3, and coil4 on ULN2003
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}


void loop(void) {
  //case 1: pot in lower half, motor running counterclockwise
  while((potPos = analogRead(pot)) <= 512) { //this line reads/updates potPos every loop iteration
    //mapping 10bit analog input value to analog output value, delayTime increases with analog signal increase
    delayTime = map(potPos, 0, 512, 800,10000);
    //calls reverse drive function with delayTime as its only parameter
    reverseDrive(delayTime);

    //calculating input voltage from analog signal
    inputVoltage = potPos * (5.0/1023.0);

    //printing needed table values
    Serial.print(inputVoltage);
    Serial.print(", ");
    Serial.println(delayTime);
  }

  //case 2: pot in upper half, motor running clockwise
  while((potPos = analogRead(pot)) > 512) {
    //mapping 10bit analog input value to analog output value, delayTime decreases 
    //with analog signal increase
    delayTime = map(potPos, 513, 1023, 10000,800);
    //calls forward drive function with delayTime as its only parameter
    forwardDrive(delayTime);

    //calculating input voltage from analog signal
    inputVoltage = potPos * (5.0/1023.0);

    //printing needed table values
    Serial.print(inputVoltage);
    Serial.print(", ");
    Serial.println(delayTime);
    }
}


//function in order to organize digitalWrite actions, makes code cleaner
void pinWrite(int pin1,int pin2,int pin3,int pin4) {
  digitalWrite(in1,pin1);
  digitalWrite(in2,pin2);
  digitalWrite(in3,pin3);
  digitalWrite(in4,pin4);
}


//function in order to complete 1 step of the stepper motor (counterclockwise)
void reverseDrive(int us){
  //calls pinWrite 8 times to make 1 step of the motor, with "us" microsecond delay between each
  //coil activation
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

//function in order to complete 1 step of the stepper motor (clockwise)
void forwardDrive(int us){
  //calls pinWrite 8 times to make 1 step of the motor, with "us" microsecond delay between each
  //coil activation
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
