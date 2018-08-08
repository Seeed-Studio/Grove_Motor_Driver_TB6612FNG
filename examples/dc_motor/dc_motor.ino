#include "Grove_Motor_Driver_TB6612FNG.h"
#include <Wire.h>

MotorDriver motor;

void setup()
{
    // join I2C bus (I2Cdev library doesn't do this automatically)
    Wire.begin();
    Serial.begin(9600);
    motor.init();
}

void loop()
{
    // drive a dc motor at speed=255, clockwise
    motor.dcMotorRun(MOTOR_CHA, 255);
    delay(2000);
    
    // brake
    motor.dcMotorBrake(MOTOR_CHA);
    delay(2000);

    // drive a dc motor at speed=150, anticlockwise
    motor.dcMotorRun(MOTOR_CHA, -150);
    delay(2000);

    // stop the motor
    motor.dcMotorStop(MOTOR_CHA);
    delay(2000);

}