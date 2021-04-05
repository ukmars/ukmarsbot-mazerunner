/*
 * File: user.cpp
 * Project: vw-control
 * File Created: Wednesday, 24th March 2021 2:10:17 pm
 * Author: Peter Harrison
 * -----
 * Last Modified: Sunday, 4th April 2021 11:20:26 pm
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

#include "user.h"
#include "encoders.h"
#include "motion.h"
#include "motors.h"
#include "reports.h"
#include "sensors.h"
#include "tests.h"
#include <Arduino.h>

// to avoid conflicts with other code, you might want to name all the functions
// in this file starting with user_
// and yes, I know there are more canonical ways to do that :)

// for example:
void user_follow_wall() {
  // This is just an example and not expected to do anything
}

void run_mouse(int function) {
  switch (function) {
    case 0:
      Serial.println(F("OK"));
      break;
    case 1:
      // enter your function call here
      // NOTE: will start on button click
      break;
    case 2:
      // enter your function call here
      break;
    case 3:
      // enter your function call here
      break;
    case 4:
      // enter your function call here
      break;
    case 5:
      // enter your function call here
      break;
    case 6:
      // enter your function call here
      break;
    case 7:
      // enter your function call here
      break;
    case 8:
      // enter your function call here
      break;
    case 9:
      // enter your function call here
      break;
    case 10:
      // enter your function call here
      break;
    case 11:
      // reserved
      break;
    case 12:
      // reserved
      break;
    case 13:
      // reserved
      break;
    case 14:
      // reserved
      break;
    case 15:
      user_follow_wall();
      break;
    default:
      // do nothing
      break;
  }
};
