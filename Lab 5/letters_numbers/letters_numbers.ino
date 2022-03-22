#include <Arduino.h>
// defining pins
#define shift 10
#define latch 9
#define data 8

// arrays for simplifying code later
boolean A[8] = {1,1,1,0,1,1,1,0};// A 
boolean b[8] = {0,0,1,1,1,1,1,0};// b
boolean C[8] = {1,0,0,1,1,1,0,0};// C
boolean d[8] = {0,1,1,1,1,0,1,0};// d
boolean E[8] = {1,0,0,1,1,1,1,0};// E
boolean F[8] = {1,0,0,0,1,1,1,0};// F
boolean dp[8] = {0,0,0,0,0,0,0,1};// decimal point (dp)

boolean zero[8] = {1,1,1,1,1,1,0,0};// 0
boolean one[8] = {0,1,1,0,0,0,0,0};// 1
boolean two[8] = {1,1,0,1,1,0,1,0};// 2
boolean three[8] = {1,1,1,1,0,0,1,0};// 3
boolean four[8] = {0,1,1,0,0,1,1,0};// 4
boolean five[8] = {1,0,1,1,0,1,1,0};// 5
boolean six[8] = {1,0,1,1,1,1,1,0};// 6
boolean seven[8] = {1,1,1,0,0,0,0,0};// 7
boolean eight[8] = {1,1,1,1,1,1,1,0};// 8
boolean nine[8] = {1,1,1,0,0,1,1,0};// 9


void writeRegister(boolean register_vals[8]) {
    /*  
    Set low initially so that, when set high later,
    an empty register is loaded
    */
    digitalWrite(latch, LOW);


    /* iterates over register_vals to write all 8 values 
    from array to register
    */
    for(int i = 7; i >=0; i--) {
        digitalWrite(shift, LOW);// shifts output pin with each iteration
        digitalWrite(data, register_vals[i]);// actually writing the value
        digitalWrite(shift, HIGH);
        
        // printing values to serial output
        Serial.print(register_vals[i]);
        Serial.print(",");
    }

    Serial.print("\n");
    digitalWrite(latch, HIGH);// loads a new, empty register
}

void setup() {
    pinMode(latch, OUTPUT);
    pinMode(data, OUTPUT);
    pinMode(shift, OUTPUT);

    Serial.begin(9600);
}


void loop() {
    // writing numbers to display
    writeRegister(zero);
    delay(500);
    writeRegister(one);
    delay(500);
    writeRegister(two);
    delay(500);
    writeRegister(three);
    delay(500);
    writeRegister(four);
    delay(500);
    writeRegister(five);
    delay(500);
    writeRegister(six);
    delay(500);
    writeRegister(seven);
    delay(500);
    writeRegister(eight);
    delay(500);
    writeRegister(nine);
    delay(500);

    // writing letters to display
    writeRegister(A);
    delay(500);
    writeRegister(b);
    delay(500);
    writeRegister(C);
    delay(500);
    writeRegister(d);
    delay(500);
    writeRegister(E);
    delay(500);
    writeRegister(F);
    delay(500);
    writeRegister(dp);
    delay(500);
}