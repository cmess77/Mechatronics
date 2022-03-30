#include <Arduino.h>
#include <Wire.h>


void setup() {
    Wire.begin(4);
    Wire.onReceive(receiveEvent);
    Serial.begin(9600);
}


void loop() {
    delay(100);
}


void receiveEvent(int how_many) {
    while(1 < Wire.available()) {
        char temp = Wire.read();
        Serial.print(temp);
    }
  	int x = Wire.read();
  	Serial.println(x);
}