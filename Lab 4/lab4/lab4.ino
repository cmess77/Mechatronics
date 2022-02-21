#include <Arduino.h>

#define trigPin 9
#define echoPin 10
#define photoPin A1
#define thermPin A0

int photoData, thermData,timeElapse;
float duration,distance, ultraData;

void setup() {
    Serial.begin(9600);

    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void loop() {
    //photoData = analogRead(photoPin);
    //Serial.println(photoData);
    //delay(100);

    digitalWrite(trigPin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    ultraData = (duration * 0.0345) * 0.5; //in cenimeters
    Serial.println(ultraData);
}