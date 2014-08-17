/*
 * SimpleDCMotor.h
 *
 * Simple Arduino library to interface Arduino motor shield (rev 3)
 * Uses DC motors, so may (probably) won't be suitable for use with steppers.
 *
 *  Created on: Aug 17, 2014
 *      Author: Robin Aggleton
 */

#ifndef SIMPLEDCMOTOR_H_
#define SIMPLEDCMOTOR_H_

#include "Arduino.h"

class SimpleDCMotor {
public:
	SimpleDCMotor(int dirPin, int pwmPin, int brakePin); // constructor
	void run(double speed); // run the motor at a given speed, >0 for forwards, <0 for backwards
	void run(); // run the motor at whatever was the last stored speed (either via run(speed), or setSpeed(speed))
	void brake(); // stop the motor
	void setSpeed(double speed); // set speed of motors

private:
	int _dirPin;
	int _pwmPin;
	int _brakePin;
	int _speed; // -100 -> 100, need to convert to 0->255 + direction
};

#endif /* SIMPLEDCMOTOR_H_ */
