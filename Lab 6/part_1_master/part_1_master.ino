#include <Arduino.h>
#include <Wire.h>

int x = 0;
char even[] = "EVEN ";
char odd[] = "ODD  ";


void setup() {
    Serial.begin(9600);
    Wire.begin();
}

void loop() {
  while(x < 101) {
    Serial.println(x);
    
    if((x % 2) == 0) {
        Wire.beginTransmission(5);
        Wire.write(even);
      	Wire.write(x);
        Wire.endTransmission();
    }

    else {
        Wire.beginTransmission(4);
        Wire.write(odd);
      	Wire.write(x);
        Wire.endTransmission();
    }

    x++;
    delay(100);
  }
}