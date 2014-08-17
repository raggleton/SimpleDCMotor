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

class SimpleDCMotor
{
	public:
		SimpleDCMotor(int dirPin, int pwmPin, int brakePin);
		void forward();
		void backward();
		void brake();
		void setSpeed(double speed); // user passes % speed (0 -> 100)

	private:
		int _dirPin;
		int _pwmPin;
		int _brakePin;
		int _speed; // 0 -> 255, raw value to use with analogWrite()
};



#endif /* SIMPLEDCMOTOR_H_ */
