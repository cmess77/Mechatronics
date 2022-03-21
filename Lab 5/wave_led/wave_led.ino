#include <Arduino.h>
// defining pins
#define shift 10
#define latch 9
#define data 8

// arrays for simplifying code later
boolean led_0[8] = {0,0,0,0,0,0,0,1};// left led
boolean led_1[8] = {0,0,0,0,0,0,1,0};
boolean led_2[8] = {0,0,0,0,0,1,0,0};
boolean led_3[8] = {0,0,0,0,1,0,0,0};
boolean led_4[8] = {0,0,0,1,0,0,0,0};
boolean led_5[8] = {0,0,1,0,0,0,0,0};
boolean led_6[8] = {0,1,0,0,0,0,0,0};
boolean led_7[8] = {1,0,0,0,0,0,0,0};// right led



void writeRegister(boolean register_vals[8]) {
    digitalWrite(latch, LOW); // allows us to write data to mux

    /* iterates over register_vals to write all 8 values 
    from register to mux
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
    digitalWrite(latch, HIGH);// disallows data transfer to mux
}

void setup() {
    pinMode(latch, OUTPUT);
    pinMode(data, OUTPUT);
    pinMode(shift, OUTPUT);

    Serial.begin(9600);
}


void loop() {
    // writing numbers to display
    writeRegister(led_0);
    delay(500);
    writeRegister(led_1);
    delay(500);
    writeRegister(led_2);
    delay(500);
    writeRegister(led_3);
    delay(500);
    writeRegister(led_4);
    delay(500);
    writeRegister(led_5);
    delay(500);
    writeRegister(led_6);
    delay(500);
    writeRegister(led_7);
    delay(500);
    writeRegister(led_6);
    delay(500);
    writeRegister(led_5);
    delay(500);
    writeRegister(led_4);
    delay(500);
    writeRegister(led_3);
    delay(500);
    writeRegister(led_2);
    delay(500);
    writeRegister(led_1);
    delay(500);
}