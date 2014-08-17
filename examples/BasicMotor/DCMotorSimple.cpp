/**
 * Simple example script of how to use SimpleDCMotor library with motor shield.
 *
 * Just plug the shield into the Arduino (assuming something like an Uno),
 * then connect the 2 wires of each motor to the +/- of A & B (each controls 1 motor).
 * Then upload this script, attach power and go!
 *
 * Note that the Motor shield requires a SEPARATE source of power, NOT USB.
 * I use 4x1.5V AA batteries (although a bit undervolted?).
 *
 * Robin Aggleton, created 17/8/14
 */

#include <SimpleDCMotor.h>

// define pins on Arduino motor shield
const int pwmA = 3;
const int pwmB = 11;
const int brakeA = 9;
const int brakeB = 8;
const int dirA = 12;
const int dirB = 13;

// setup global motors here (so both setup() and loop() can see them)
SimpleDCMotor R(dirA, pwmA, brakeA);
SimpleDCMotor L(dirB, pwmB, brakeB);

void setup() {
	Serial.begin(9600);
	// Set initial speed of motors as %s. So here they are full speed.
	R.setSpeed(100.);
	L.setSpeed(100.);
}

void loop() {
	// Do some basic forwards/backwards movement, then pause.
	R.forward();
	L.forward();
	delay(1000);
	R.backward();
	L.backward();
	delay(1000);
	R.brake();
	L.brake();
	delay(1000);
}
