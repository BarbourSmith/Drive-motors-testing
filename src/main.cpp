// Simple hardware test firmware for the Maslow 4.
// Drives all four DC motors at full speed continuously using the exact same
// DCMotor class and pin definitions as the Maslow 4 firmware.

#include <Arduino.h>
#include "DCMotor.h"

// Motor pin and channel definitions (copied from Maslow 4 firmware Maslow.cpp)
#define tlIn1Pin     45
#define tlIn1Channel 0
#define tlIn2Pin     21
#define tlIn2Channel 1
#define tlADCPin     18

#define trIn1Pin     42
#define trIn1Channel 2
#define trIn2Pin     41
#define trIn2Channel 3
#define trADCPin     6

#define blIn1Pin     37
#define blIn1Channel 4
#define blIn2Pin     36
#define blIn2Channel 5
#define blADCPin     8

#define brIn1Pin     9
#define brIn1Channel 6
#define brIn2Pin     3
#define brIn2Channel 7
#define brADCPin     7

DCMotor tlMotor, trMotor, blMotor, brMotor;

void setup() {
    Serial.begin(115200);
    Serial.println("Maslow 4 motor test: driving all motors at full speed");

    tlMotor.begin(tlIn1Pin, tlIn2Pin, tlADCPin, tlIn1Channel, tlIn2Channel);
    trMotor.begin(trIn1Pin, trIn2Pin, trADCPin, trIn1Channel, trIn2Channel);
    blMotor.begin(blIn1Pin, blIn2Pin, blADCPin, blIn1Channel, blIn2Channel);
    brMotor.begin(brIn1Pin, brIn2Pin, brADCPin, brIn1Channel, brIn2Channel);

    tlMotor.fullOut();
    trMotor.fullOut();
    blMotor.fullOut();
    brMotor.fullOut();

    Serial.println("All four motors running at full speed.");
}

void loop() {
    // Nothing to do - PWM outputs are maintained by hardware.
}
