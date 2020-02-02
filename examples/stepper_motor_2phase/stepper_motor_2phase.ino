#include "Grove_Motor_Driver_TB6612FNG.h"
#include <Wire.h>

MotorDriver motor;

// set speed to 120 revolutions per minute
uint16_t rpm = 120;

void setup() {
    // join I2C bus (I2Cdev library doesn't do this automatically)
    Wire.begin();
    Serial.begin(9600);
    motor.init();
}

void loop() {
    // Stepper run 10 rounds at HALF_STEP mode, this takes about 5 seconds
    // At HALF_STEP mode, one step = 0.9 degree, so it takes 400 step to go a round
    motor.stepperRun(HALF_STEP, 400 * 10, rpm);
    delay(6000);

    // Stepper run 10 rounds at MICRO_STEPPING mode, this takes about 5 seconds
    // At MICRO_STEPPING mode, one step = 1.8 degree, so it takes 200 step to go a round
    // At this mode, stepper runs very smoothly
    motor.stepperRun(MICRO_STEPPING, -200 * 10, rpm);
    delay(6000);

    // Stepper run 10 rounds at FULL_STEP mode, this takes about 5 seconds
    // At FULL_STEP mode, one step = 1.8 degree, so it takes 200 step to go a round
    motor.stepperRun(FULL_STEP, 200 * 10, rpm);
    delay(6000);

    // Stepper run 10 rounds at WAVE_DRIVE mode, this takes about 5 seconds
    // At WAVE_DRIVE mode, one step = 1.8 degree, so it takes 200 step to go a round
    motor.stepperRun(WAVE_DRIVE, -200 * 10, rpm);
    delay(6000);

    // Stepper keeps moving anticlosewise
    motor.stepperKeepRun(MICRO_STEPPING, rpm, true);
    delay(3000);

    // stop
    motor.stepperStop();
    delay(3000);

    // Stepper keeps moving anticlosewise
    motor.stepperKeepRun(MICRO_STEPPING, rpm, false);
    delay(3000);

    // stop
    motor.stepperRun(MICRO_STEPPING, 0, rpm);
    delay(3000);
}