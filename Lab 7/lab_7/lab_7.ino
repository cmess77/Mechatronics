#include <Arduino.h>

const int BUTTON0 = 6;
const int BUTTON1 = 7;
const int BUTTON2 = 8;
const int BUTTON3 = 9;
const int BUTTON4 = 10;
const int SPEAKER = 12;

float e_low = 20.6;
float f_low = 21.83;
float g = 24.5;
float a = 27.5;
float b = 30.87;
float c = 32.7;
float d = 36.71;
float e_high = 41.2;
float f_high = 43.65;

int octave_flag = -1;


void setup() {
    Serial.begin(9600);
    pinMode(BUTTON0, INPUT_PULLUP);
    pinMode(BUTTON1, INPUT_PULLUP);
    pinMode(BUTTON2, INPUT_PULLUP);
    pinMode(BUTTON3, INPUT_PULLUP);
    pinMode(BUTTON4, INPUT_PULLUP);
    pinMode(SPEAKER, OUTPUT);
}

void loop() {
    // while loop for normal octave
    while(octave_flag == 0) {
        if((digitalRead(BUTTON0) == 0) || (digitalRead(BUTTON1) == 0) || (digitalRead(BUTTON2) == 0) || (digitalRead(BUTTON3) == 0) || (digitalRead(BUTTON4) == 0)) {
            if(digitalRead(BUTTON0) == 0) {
                Serial.println("Playing e_low");
                tone(SPEAKER, e_low);
            }
            if((digitalRead(BUTTON0) ==0) && (digitalRead(BUTTON1) == 0)) {
                Serial.println("Playing f_low");
                tone(SPEAKER, f_low);
            }
            if((digitalRead(BUTTON1) ==0)) {
                Serial.println("Playing  g");
                tone(SPEAKER, g);
            }
            if((digitalRead(BUTTON1) ==0) && (digitalRead(BUTTON2) == 0)) {
                Serial.println("Playing a");
                tone(SPEAKER, a);
            }
            if((digitalRead(BUTTON2) ==0)) {
                Serial.println("Playing b");
                tone(SPEAKER, b);
            }
            if((digitalRead(BUTTON2) ==0) && (digitalRead(BUTTON3) == 0)) {
                Serial.println("Playing c");
                tone(SPEAKER, c);
            }
            if((digitalRead(BUTTON3) ==0)) {
                Serial.println("Playing d");
                tone(SPEAKER, d);
            }
            if((digitalRead(BUTTON3) ==0) && (digitalRead(BUTTON4) == 0)) {
                Serial.println("Playing e_high");
                tone(SPEAKER, e_high);
            }
            if((digitalRead(BUTTON4) ==0)) {
                Serial.println("Playing f_high");
                tone(SPEAKER, f_high);
            }
            if((digitalRead(BUTTON0) ==0) && (digitalRead(BUTTON1) == 0) && (digitalRead(BUTTON2) == 0)) {
                octave_flag = -1;
            }
    
            if((digitalRead(BUTTON2) ==0) && (digitalRead(BUTTON3) == 0) && (digitalRead(BUTTON4) == 0)) {
                octave_flag = 1;
            }
        }
        
        else {
          noTone(SPEAKER);
        }
    }
    // while loop for higher octave
    while(octave_flag == 1) {
        if((digitalRead(BUTTON0) == 0) || (digitalRead(BUTTON1) == 0) || (digitalRead(BUTTON2) == 0) || (digitalRead(BUTTON3) == 0) || (digitalRead(BUTTON4) == 0)) {
            if(digitalRead(BUTTON0) == 0) {
                Serial.println("Playing e_low * 2");
                tone(SPEAKER, e_low * 2);
            }
            if((digitalRead(BUTTON0) ==0) && (digitalRead(BUTTON1) == 0)) {
                Serial.println("Playing f_low * 2");
                tone(SPEAKER, f_low * 2);
            }
            if((digitalRead(BUTTON1) ==0)) {
                Serial.println("Playing g * 2");
                tone(SPEAKER, g * 2);
            }
            if((digitalRead(BUTTON1) ==0) && (digitalRead(BUTTON2) == 0)) {
                Serial.println("Playing a * 2");
                tone(SPEAKER, a * 2);
            }
            if((digitalRead(BUTTON2) ==0)) {
                Serial.println("Playing b * 2");
                tone(SPEAKER, b * 2);
            }
            if((digitalRead(BUTTON2) ==0) && (digitalRead(BUTTON3) == 0)) {
                Serial.println("Playing c * 2");
                tone(SPEAKER, c * 2);
            }
            if((digitalRead(BUTTON3) ==0)) {
                Serial.println("Playing d * 2");
                tone(SPEAKER, d * 2);
            }
            if((digitalRead(BUTTON3) ==0) && (digitalRead(BUTTON4) == 0)) {
                Serial.println("Playing e_high * 2");
                tone(SPEAKER, e_high * 2);
            }
            if((digitalRead(BUTTON4) ==0)) {
                Serial.println("Playing f_high * 2");
                tone(SPEAKER, f_high * 2);
            }
            if((digitalRead(BUTTON0) ==0) && (digitalRead(BUTTON1) == 0) && (digitalRead(BUTTON2) == 0)) {
                octave_flag = 0;
            }
        }

        else {
            noTone(SPEAKER);
        }
    }
    // while loop for lower octave
    while(octave_flag == -1) {
        if((digitalRead(BUTTON0) == 0) || (digitalRead(BUTTON1) == 0) || (digitalRead(BUTTON2) == 0) || (digitalRead(BUTTON3) == 0) || (digitalRead(BUTTON4) == 0)) {
            if(digitalRead(BUTTON0) == 0) {
                Serial.println("Playing e_low / 2");
                tone(SPEAKER, e_low / 2);
            }
            if((digitalRead(BUTTON0) ==0) && (digitalRead(BUTTON1) == 0)) {
                Serial.println("Playing f_low / 2");
                tone(SPEAKER, f_low / 2);
            }
            if((digitalRead(BUTTON1) ==0)) {
                Serial.println("Playing g / 2");
                tone(SPEAKER, g / 2);
            }
            if((digitalRead(BUTTON1) ==0) && (digitalRead(BUTTON2) == 0)) {
                Serial.println("Playing a / 2");
                tone(SPEAKER, a / 2);
            }
            if((digitalRead(BUTTON2) ==0)) {
                Serial.println("Playing b / 2");
                tone(SPEAKER, b / 2);
            }
            if((digitalRead(BUTTON2) ==0) && (digitalRead(BUTTON3) == 0)) {
                Serial.println("Playing c / 2");
                tone(SPEAKER, c / 2);
            }
            if((digitalRead(BUTTON3) ==0)) {
                Serial.println("Playing d / 2");
                tone(SPEAKER, d / 2);
            }
            if((digitalRead(BUTTON3) ==0) && (digitalRead(BUTTON4) == 0)) {
                Serial.println("Playing e_high / 2");
                tone(SPEAKER, e_high / 2);
            }
            if((digitalRead(BUTTON4) ==0)) {
                Serial.println("Playing f_high / 2");
                tone(SPEAKER, f_high / 2);
            }
            if((digitalRead(BUTTON2) ==0) && (digitalRead(BUTTON3) == 0) && (digitalRead(BUTTON4) == 0)) {
                octave_flag = 0;
            }
        }

        else {
          noTone(SPEAKER);
        }
    }
}
