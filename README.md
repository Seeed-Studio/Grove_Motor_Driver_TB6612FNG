# Grove - Motor Driver(TB6612FNG)  [![Build Status](https://travis-ci.com/Seeed-Studio/Grove_Motor_Driver_TB6612FNG.svg?branch=master)](https://travis-ci.com/Seeed-Studio/Grove_Motor_Driver_TB6612FNG)

This is the Arduino library of Grove - Motor Driver(TB6612FNG), based on I2C.

## Examples

### dc_motor
This example shows how to drive a dc motor. Connect a dc motor to the same channel(A1 and A2, or B1 and B2) first. Add extra power supply to `VIN` and `GND` if necessary. Then upload this example to your arduino board.


You must have found there are two similar function: `dcMotorBrake` and `dcMotorStop`. The difference between them is that `dcMotorBrake` will give a reverse force to make the motor stop

### stepper_motor_2phase
This example shows how to drive a 2phase stepper motor. 

Different with dc motor, there is just one function to drive a stepper: `stepperRun`. And our library offers 4 ways to drive: `FULL_STEP`, `WAVE_DRIVE`, `HALF_STEP` and `MICRO_STEPPING`.


More informations about stepper motor: [Wikipedia](https://en.wikipedia.org/wiki/Stepper_motor) and [What is full step, half step, and microstepping](https://www.rs-online.com/designspark/stepper-motors-and-drives-what-is-full-step-half-step-and-microstepping).


----

This software is written by Jerry Yip for seeed studio and is licensed under [The MIT License](http://opensource.org/licenses/mit-license.php). Check License.txt for more information.<br>

Contributing to this software is warmly welcomed. You can do this basically by<br>
[forking](https://help.github.com/articles/fork-a-repo), committing modifications and then [pulling requests](https://help.github.com/articles/using-pull-requests) (follow the links above<br>
for operating guide). Adding change log and your contact into file header is encouraged.<br>
Thanks for your contribution.

Seeed Studio is an open hardware facilitation company based in Shenzhen, China. <br>
Benefiting from local manufacture power and convenient global logistic system, <br>
we integrate resources to serve new era of innovation. Seeed also works with <br>
global distributors and partners to push open hardware movement.<br>


[![Analytics](https://ga-beacon.appspot.com/UA-46589105-3/grove-motor-driver-tb6612fng)](https://github.com/igrigorik/ga-beacon)
