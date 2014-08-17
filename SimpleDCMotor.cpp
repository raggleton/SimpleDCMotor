/*
 * SimpleDCMotor.cpp
 *
 * Simple Arduino library to interface Arduino motor shield (rev 3)
 * Uses DC motors, so may (probably) won't be suitable for use with steppers.
 *
 *  Created on: Aug 17, 2014
 *      Author: Robin Aggleton
 */

#include "Arduino.h"
#include "SimpleDCMotor.h"

SimpleDCMotor::SimpleDCMotor(int dirPin, int pwmPin, int brakePin)
{
	// Setup pins for motor
	_dirPin = dirPin;
	_pwmPin = pwmPin;
	_brakePin = brakePin;
	_speed = 0;
	pinMode(_dirPin, OUTPUT);
	pinMode(_pwmPin, OUTPUT);
	pinMode(_brakePin, OUTPUT);
}

void SimpleDCMotor::forward()
{
	analogWrite(_pwmPin, _speed);
	digitalWrite(_brakePin, LOW);
	digitalWrite(_dirPin, HIGH);
}

void SimpleDCMotor::backward()
{
	analogWrite(_pwmPin, _speed);
	digitalWrite(_brakePin, LOW);
	digitalWrite(_dirPin, LOW);
}

void SimpleDCMotor::brake()
{
	digitalWrite(_brakePin, HIGH);
	analogWrite(_pwmPin, 0);
}

void SimpleDCMotor::setSpeed(double speed)
{
	// User passes in speed as a %
	// This translates that to 0 -> 255
	if (speed >= 100) {
		_speed = 255;
	} else {
		_speed = int(255*speed/100); // should round better here
	}
	analogWrite(_pwmPin, _speed);
}
