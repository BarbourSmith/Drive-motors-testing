// Simple hardware test firmware for the Maslow 4.
// Drives all four DC motors at full speed continuously.
//
// Motor connections (from Maslow 4 firmware / TI DRV8873 motor driver via LEDC PWM):
//   Top Left     (TL): IN1=GPIO45 (ch0), IN2=GPIO21 (ch1)
//   Top Right    (TR): IN1=GPIO42 (ch2), IN2=GPIO41 (ch3)
//   Bottom Left  (BL): IN1=GPIO37 (ch4), IN2=GPIO36 (ch5)
//   Bottom Right (BR): IN1=GPIO9  (ch6), IN2=GPIO3  (ch7)
//
// The DRV8873 is driven with complementary PWM signals:
//   Forward at full speed: IN2 = 1023 (max), IN1 = 0

#include <Arduino.h>

// PWM settings (matching Maslow 4 DCMotor driver)
#define MOTOR_PWM_FREQ 16000
#define MOTOR_PWM_RES  10
#define MOTOR_MAX_PWM  1023

// Motor pin and channel definitions
#define TL_IN1_PIN  45
#define TL_IN2_PIN  21
#define TL_CH1      0
#define TL_CH2      1

#define TR_IN1_PIN  42
#define TR_IN2_PIN  41
#define TR_CH1      2
#define TR_CH2      3

#define BL_IN1_PIN  37
#define BL_IN2_PIN  36
#define BL_CH1      4
#define BL_CH2      5

#define BR_IN1_PIN  9
#define BR_IN2_PIN  3
#define BR_CH1      6
#define BR_CH2      7

// Configure one motor's PWM channels and drive it at full speed forward.
static void motorFullSpeed(int in1Pin, int in2Pin, int ch1, int ch2) {
    ledcSetup(ch1, MOTOR_PWM_FREQ, MOTOR_PWM_RES);
    ledcAttachPin(in1Pin, ch1);

    ledcSetup(ch2, MOTOR_PWM_FREQ, MOTOR_PWM_RES);
    ledcAttachPin(in2Pin, ch2);

    // Forward full speed: IN2 high, IN1 low (matches Maslow DCMotor::fullOut())
    ledcWrite(ch1, 0);
    ledcWrite(ch2, MOTOR_MAX_PWM);
}

void setup() {
    Serial.begin(115200);
    Serial.println("Maslow 4 motor test: driving all motors at full speed");

    motorFullSpeed(TL_IN1_PIN, TL_IN2_PIN, TL_CH1, TL_CH2);
    motorFullSpeed(TR_IN1_PIN, TR_IN2_PIN, TR_CH1, TR_CH2);
    motorFullSpeed(BL_IN1_PIN, BL_IN2_PIN, BL_CH1, BL_CH2);
    motorFullSpeed(BR_IN1_PIN, BR_IN2_PIN, BR_CH1, BR_CH2);

    Serial.println("All four motors running at full speed.");
}

void loop() {
    // Nothing to do - PWM outputs are maintained by hardware.
}
