#include <Arduino.h>
// defining pins
#define shift 10
#define latch 9
#define data 8

// arrays for simplifying code later
boolean first_patt[8] = {1,0,0,0,0,0,0,1};// leftmost and rightmost
boolean second_patt[8] = {0,1,0,0,0,0,1,0};// 2nd and 7th
boolean third_patt[8] = {0,0,1,0,0,1,0,0};// 3rd and 6th
boolean fourth_patt[8] = {0,0,0,1,1,0,0,0};// 4th and 5th



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
    // setting pin modes
    pinMode(latch, OUTPUT);
    pinMode(data, OUTPUT);
    pinMode(shift, OUTPUT);

    // starting serial communication
    Serial.begin(9600);
}


void loop() {
    // doing accordion pattern
    writeRegister(first_patt);
    delay(500);
    writeRegister(second_patt);
    delay(500);
    writeRegister(third_patt);
    delay(500);
    writeRegister(fourth_patt);
    delay(500);
    writeRegister(third_patt);
    delay(500);
    writeRegister(second_patt);
    delay(500);
}