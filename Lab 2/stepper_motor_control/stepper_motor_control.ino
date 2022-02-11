//defining pin numbers in global space
#define pot A0
#define in1 7
#define in2 6
#define in3 5
#define in4 4

//defining maximum step delay
#define dT 5000000

//declaring variables for potentiometer position, stepper motor step-delay, input voltage
int potPos;
float inputVoltage, dt, dutyCycle;

void setup(void) {
  //starting serial communication
  Serial.begin(9600);
  //printing header for output table
  Serial.println("Volt(in), delayTime");

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
    //calculating input voltage from analog signal
    inputVoltage = potPos * (5.0/1023.0);

    //calculating dutyCycle
    dutyCycle = 100 - (abs((inputVoltage - 2.5)) * (100/2.5));

    //calculating dt
    dt = dT * (dutyCycle/100); 
    
    //calls forward drive function with dt as its only parameter
    reverseDrive(dt);

    //printing needed table values
    Serial.print(inputVoltage);
    Serial.print(", ");
    Serial.println(dutyCycle);
    }


  //case 2: pot in upper half, motor running clockwise
  while((potPos = analogRead(pot)) > 512) {
    //calculating input voltage from analog signal
    inputVoltage = potPos * (5.0/1023.0);

    //calculating dutyCycle
    dutyCycle = 100 - (abs((inputVoltage - 2.5)) * (100/2.5));

    //calculating dt
    dt = dT * (dutyCycle/100); 
    
    //calls forward drive function with dt as its only parameter
    forwardDrive(dt);

    //printing needed table values
    Serial.print(inputVoltage);
    Serial.print(", ");
    Serial.println(dutyCycle);
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
void reverseDrive(float delayTime){
  //calls pinWrite 8 times to make 1 step of the motor, with "delayTime" microsecond delay between each
  //coil activation
  pinWrite(1,0,0,0);
  delayMicroseconds(delayTime);
  pinWrite(1,1,0,0);
  delayMicroseconds(delayTime);
  pinWrite(0,1,0,0);
  delayMicroseconds(delayTime);
  pinWrite(0,1,1,0);
  delayMicroseconds(delayTime);
  pinWrite(0,0,1,0);
  delayMicroseconds(delayTime);
  pinWrite(0,0,1,1);
  delayMicroseconds(delayTime);
  pinWrite(0,0,0,1);
  delayMicroseconds(delayTime);
  pinWrite(1,0,0,1);
  delayMicroseconds(delayTime);
}

//function in order to complete 1 step of the stepper motor (clockwise)
void forwardDrive(float delayTime){
  //calls pinWrite 8 times to make 1 step of the motor, with "delayTime" microsecond delay between each
  //coil activation
  pinWrite(0,0,0,1);
  delayMicroseconds(delayTime);
  pinWrite(0,0,0,1);
  delayMicroseconds(delayTime);
  pinWrite(0,0,1,1);
  delayMicroseconds(delayTime);
  pinWrite(0,0,1,0);
  delayMicroseconds(delayTime);
  pinWrite(0,1,1,0);
  delayMicroseconds(delayTime);
  pinWrite(0,1,0,0);
  delayMicroseconds(delayTime);
  pinWrite(1,1,0,0);
  delayMicroseconds(delayTime);
  pinWrite(1,0,0,1);
  delayMicroseconds(delayTime);
}
