/*
    Grove_Motor_Driver_TB6612FNG.h
    A library for the Grove - Motor Driver(TB6612FNG)

    Copyright (c) 2018 seeed technology co., ltd.
    Website    : www.seeed.cc
    Author     : Jerry Yip
    Create Time: 2018-06
    Version    : 0.1
    Change Log :

    The MIT License (MIT)

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/

#ifndef __GROVE_MOTOR_DRIVER_TB6612FNG_H__
#define __GROVE_MOTOR_DRIVER_TB6612FNG_H__

#include "I2Cdev.h"

#define GROVE_MOTOR_DRIVER_DEFAULT_I2C_ADDR         0x14

#define GROVE_MOTOR_DRIVER_DEFAULT_I2C_ADDR         0x14
#define GROVE_MOTOR_DRIVER_I2C_CMD_BRAKE            0x00
#define GROVE_MOTOR_DRIVER_I2C_CMD_STOP             0x01
#define GROVE_MOTOR_DRIVER_I2C_CMD_CW               0x02
#define GROVE_MOTOR_DRIVER_I2C_CMD_CCW              0x03
#define GROVE_MOTOR_DRIVER_I2C_CMD_STANDBY          0x04
#define GROVE_MOTOR_DRIVER_I2C_CMD_NOT_STANDBY      0x05
#define GROVE_MOTOR_DRIVER_I2C_CMD_STEPPER_RUN      0x06
#define GROVE_MOTOR_DRIVER_I2C_CMD_STEPPER_STOP     0x07
#define GROVE_MOTOR_DRIVER_I2C_CMD_STEPPER_KEEP_RUN 0x08
#define GROVE_MOTOR_DRIVER_I2C_CMD_SET_ADDR         0x11


enum motor_channel_type_t {
    MOTOR_CHA = 0,
    MOTOR_CHB = 1,
};

enum stepper_mode_type_t {
    FULL_STEP = 0,
    WAVE_DRIVE = 1,
    HALF_STEP = 2,
    MICRO_STEPPING = 3,
};

class MotorDriver {
  public:
    MotorDriver();

    void init(uint8_t addr = GROVE_MOTOR_DRIVER_DEFAULT_I2C_ADDR);

    /*************************************************************
        Description
         Enter standby mode. Normally you don't need to call this, except that
         you have called notStandby() before.
        Parameter
         Null.
        Return
         Null.
    *************************************************************/
    void standby();

    /*************************************************************
        Description
         Exit standby mode. Motor driver does't do any action at this mode.
        Parameter
         Null.
        Return
         Null.
    *************************************************************/
    void notStandby();

    /*************************************************************
        Description
         Set an new I2C address.
        Parameter
         addr: 0x01~0x7f
        Return
         Null.
    *************************************************************/
    void setI2cAddr(uint8_t addr);

    /*************************************************************
        Description
         Drive a motor.
        Parameter
         chl: MOTOR_CHA or MOTOR_CHB
         speed: -255~255, if speed > 0, motor moves clockwise.
                Note that there is always a starting speed(a starting voltage) for motor.
                If the input voltage is 5V, the starting speed should larger than 100 or
                smaller than -100.
        Return
         Null.
    *************************************************************/
    void dcMotorRun(motor_channel_type_t chl, int16_t speed);

    /*************************************************************
        Description
         Brake, stop the motor immediately
        Parameter
         chl: MOTOR_CHA or MOTOR_CHB
        Return
         Null.
    *************************************************************/
    void dcMotorBrake(motor_channel_type_t chl);

    /*************************************************************
        Description
         Stop the motor slowly.
        Parameter
         chl: MOTOR_CHA or MOTOR_CHB
        Return
         Null.
    *************************************************************/
    void dcMotorStop(motor_channel_type_t chl);

    /*************************************************************
        Description
         Drive a stepper.
        Parameter
         mode:  4 driver mode: FULL_STEP,WAVE_DRIVE, HALF_STEP, MICRO_STEPPING,
                for more information: https://en.wikipedia.org/wiki/Stepper_motor#/media/File:Drive.png
         steps: The number of steps to run, range from -32768 to 32767.
                When steps = 0, the stepper stops.
                When steps > 0, the stepper runs clockwise. When steps < 0, the stepper runs anticlockwise.
         rpm:   Revolutions per minute, the speed of a stepper, range from 1 to 300.
                Note that high rpm will lead to step lose, so rpm should not be larger than 150.
        Return
         Null.
    *************************************************************/
    void stepperRun(stepper_mode_type_t mode, int16_t steps, uint16_t rpm);

    /*************************************************************
        Description
         Stop a stepper.
        Parameter
         Null.
        Return
         Null.
    *************************************************************/
    void stepperStop();

    // keeps moving(direction same as the last move, default to clockwise)
    /*************************************************************
        Description
         Keep a stepper running.
        Parameter
         mode:  4 driver mode: FULL_STEP,WAVE_DRIVE, HALF_STEP, MICRO_STEPPING,
                for more information: https://en.wikipedia.org/wiki/Stepper_motor#/media/File:Drive.png
         rpm:   Revolutions per minute, the speed of a stepper, range from 1 to 300.
                Note that high rpm will lead to step lose, so rpm should not be larger than 150.
         is_cw: Set the running direction, true for clockwise and false for anti-clockwise.

        Return
         Null.
    *************************************************************/
    void stepperKeepRun(stepper_mode_type_t mode, uint16_t rpm, bool is_cw);

  private:
    uint8_t _addr;
    uint8_t _buffer[16];
};

#endif //__GROVE_MOTOR_DRIVER_TB6612FNG_H__