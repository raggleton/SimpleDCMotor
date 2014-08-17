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

SimpleDCMotor::SimpleDCMotor(int dirPin, int pwmPin, int brakePin) :
		_dirPin(dirPin), _pwmPin(pwmPin), _brakePin(brakePin), _speed(100) {
	// Setup pins for motor
	pinMode(_dirPin, OUTPUT);
	pinMode(_pwmPin, OUTPUT);
	pinMode(_brakePin, OUTPUT);
}

void SimpleDCMotor::run(double speed) {
	setSpeed(speed);
	digitalWrite(_brakePin, LOW);
	if (speed > 0) {
		digitalWrite(_dirPin, HIGH);
	} else {
		digitalWrite(_dirPin, LOW);
	}
}

void SimpleDCMotor::run() {
	run(_speed);
}

void SimpleDCMotor::brake() {
	digitalWrite(_brakePin, HIGH);
}

void SimpleDCMotor::setSpeed(double speed) {
	// Takes in speed as a %, with sign as direction
	// we don't care about direction - just how fast to turn the wheels!
	_speed = speed; // store for future
	speed = constrain(abs(speed), 0., 100.); // check it's actually 0 -> 100
	// Need to translate that to 0 -> 255 to send to pwm pin
	analogWrite(_pwmPin, round(255 * speed / 100.));
}
