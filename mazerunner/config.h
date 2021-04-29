/*
 * File: config.h
 * Project: mazerunner
 * File Created: Monday, 29th March 2021 11:04:59 pm
 * Author: Peter Harrison
 * -----
 * Last Modified: Wednesday, 14th April 2021 1:12:15 pm
 * Modified By: Peter Harrison
 * -----
 * MIT License
 *
 * Copyright (c) 2021 Peter Harrison
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do
 * so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef CONFIG_H
#define CONFIG_H

#include <arduino.h>

// force rewrite of EEPROM settings. Set this when developing
#define ALWAYS_USE_DEFAULT_SETTINGS 1
//***************************************************************************//
const bool USER_MODE = false;

//***************************************************************************//
// We need to know about the drive mechanics.

const float WHEEL_DIAMETER = 33.298; // Adjust on test
const float ENCODER_PULSES = 12.0;
const float GEAR_RATIO = 19.54;

// Mouse radius is the distance between the contact patches of the drive wheels.
// A good starting approximation is half the distance between the wheel centres.
// After testing, you may find the working value to be larger or smaller by some
// small amount.
const float MOUSE_RADIUS = 39.50; // Adjust on test

// The robot is likely to have wheels of different diameters and that must be
// compensated for if the robot is to reliably drive in a straight line
const float ROTATION_BIAS = 0.0025; // Negative makes robot curve to left

//***************************************************************************//

//*** MOTION CONTROL CONSTANTS **********************************************//

// forward motion controller constants
const float FWD_KP = 2.0;
const float FWD_KD = 1.1;

// rotation motion controller constants
const float ROT_KP = 2.1;
const float ROT_KD = 1.2;

// controller constants for the steering controller
const float STEERING_KP = 0.25;
const float STEERING_KD = 0.00;
const float STEERING_ADJUST_LIMIT = 10.0; // deg/s

// Motor Feedforward
const float SPEED_FF = (1.0 / 280.0);
const float BIAS_FF = (23.0 / 280.0);

// encoder polarity is set to account for reversal of the encoder phases
const int ENCODER_LEFT_POLARITY = (-1);
const int ENCODER_RIGHT_POLARITY = (1);

// similarly, the motors may be wired with different polarity and that
// is defined here so that setting a positive voltage always moves the robot
// forwards
const int MOTOR_LEFT_POLARITY = (1);
const int MOTOR_RIGHT_POLARITY = (-1);

//***************************************************************************//

//***** PERFORMANCE CONSTANTS************************************************//
// search and run speeds in mm/s and mm
const float DEFAULT_TURN_SPEED = 300;
const float DEFAULT_SEARCH_SPEED = 400;
const float DEFAULT_MAX_SPEED = 800;
const float DEFAULT_SEARCH_ACCEL = 2000;
//***************************************************************************//

//***** SENSOR CALIBRATION **************************************************//
// wall sensor thresholds and constants
// RAW values for the front sensor when the robot is backed up to a wall
const int FRONT_CALIBRATION = 70;
// RAW values for the side sensors when the robot is centred in a cell
// and there is no wall ahead
const int LEFT_CALIBRATION = 97;
const int RIGHT_CALIBRATION = 92;

// This is the normalised value seen by the front sensor when the mouse is
// in its calibration position
const int LEFT_NOMINAL = 100;
const int FRONT_NOMINAL = 100;
const int RIGHT_NOMINAL = 100;

// Sensor brightness adjustment factor. The compiler calculates these so it saves processor time
const float FRONT_SCALE = (float)FRONT_NOMINAL / FRONT_CALIBRATION;
const float LEFT_SCALE = (float)LEFT_NOMINAL / LEFT_CALIBRATION;
const float RIGHT_SCALE = (float)RIGHT_NOMINAL / RIGHT_CALIBRATION;

// the values above which, a wall is seen
const int LEFT_THRESHOLD = 40;  // minimum value to register a wall
const int FRONT_THRESHOLD = 20; // minimum value to register a wall
const int RIGHT_THRESHOLD = 40; // minimum value to register a wall

//***************************************************************************//
//***************************************************************************//
// Some physical constants that are likely to be board -specific

// with robot against back wall, how much travel is there to the cell center?
const int BACK_WALL_TO_CENTER = 47;

//***************************************************************************//

// Control loop timing. Pre-calculate to save time in interrupts
const float LOOP_FREQUENCY = 500.0;
const float LOOP_INTERVAL = (1.0 / LOOP_FREQUENCY);

//***************************************************************************//
// change the revision if the settings structure changes to force rewrte of EEPROM
const int SETTINGS_REVISION = 10319;
const uint32_t BAUDRATE = 115200;
const int DEFAULT_DECIMAL_PLACES = 5;
const int EEPROM_ADDR_SETTINGS = 0x0000;

//***************************************************************************//
// set this to zero to disable profile data logging over serial
#define DEBUG_LOGGING 1
// time between logged lined when reporting is enabled (milliseconds)
const int REPORTING_INTERVAL = 10;

//***************************************************************************//
const float MAX_MOTOR_VOLTS = 6.0;

//**** HARDWARE CONFIGURATION ***********************************************//
const uint8_t ENCODER_LEFT_CLK = 2;
const uint8_t ENCODER_RIGHT_CLK = 3;
const uint8_t ENCODER_LEFT_B = 4;
const uint8_t ENCODER_RIGHT_B = 5;
const uint8_t USER_IO = 6;
const uint8_t LED_RIGHT = 6; // an alias for USER_IO
const uint8_t MOTOR_LEFT_DIR = 7;
const uint8_t MOTOR_RIGHT_DIR = 8;
const uint8_t MOTOR_LEFT_PWM = 9;
const uint8_t MOTOR_RIGHT_PWM = 10;
const uint8_t LED_LEFT = 11; // an alias for EMITTER_B
const uint8_t EMITTER_A = 11;
const uint8_t EMITTER_B = 12;
const uint8_t EMITTER = 12; // alias for pin 12

// these are the sensor ADC channels in case we have no special use for a given channel
const uint8_t SENSOR_0 = A0;
const uint8_t SENSOR_1 = A1;
const uint8_t SENSOR_2 = A2;
const uint8_t SENSOR_3 = A3;
const uint8_t SENSOR_4 = A4;
const uint8_t SENSOR_5 = A5;

// convenient aliases for the basic wall sensor channels
const uint8_t RIGHT_WALL_SENSOR = A0;
const uint8_t FRONT_WALL_SENSOR = A1;
const uint8_t LEFT_WALL_SENSOR = A2;

const uint8_t FUNCTION_PIN = A6;
const uint8_t BATTERY_VOLTS = A7;
//***************************************************************************//

#endif
