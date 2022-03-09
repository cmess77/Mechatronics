#include <Arduino.h>

#define trigPin 9
#define echoPin 10
#define photoPin A1
#define thermPin A0

int photoData, thermData, timeElapse;
float duration, ultraPositionInches, ultraPositionFeet;

void setup() {
    Serial.begin(9600);

    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(thermPin,INPUT);
    pinMode(photoPin, INPUT);
}

void loop() {
    //photoSensor();
    //thermSensor();
    ultraSensor();
}

void ultraSensor(void) {
    digitalWrite(trigPin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    //ultraPositionInches = (duration * 0.0345) * 0.5 * 0.3937008; //in inches
    ultraPositionFeet = (duration * 0.0345) * 0.5 * 0.3937008 / 12; //in feet

    //Serial.println(ultraPositionInches);
    Serial.println(ultraPositionFeet);
    delay(100);
}

void photoSensor(void) {
    photoData = analogRead(photoPin);
    Serial.println(photoData);
    delay(100);
}

void thermSensor(void) {
    thermData = analogRead(thermPin);
    Serial.println(thermData);
    delay(100);
}