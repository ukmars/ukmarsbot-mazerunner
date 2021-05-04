# ukmarsbot-mazerunner

This repository will hold a complete set of code for a version of UKMARSBOT that can run in a classic micromouse maze.

The main branch has the functional components. The implementation of these into a working micromouse are in the Dorothy branch.

The code assumes you have a standard UKMARSBOT assembled, using an Arduino nano with a basic wall sensor connected.

### Arduino IDE users

For the impatient, if you are wanting to run this code in the Arduino IDE then you can download or clone the complete repository and simply open the mazerunner.ino file. The rduino IDE will be able to build and flash the prject. It will also open all the other files in the mazerunner directory. That may be surprising to you but it is just trying to be helpful.


### Platform IO users

The project is maintained and developed using PlatformIO with Visual Studio Code. If you have not used this as a development platform, I highly recommend it as a huge improvement over the very dated Arduino IDE. You can find instructions for installing VSCode and PlatformIO at https://ukmars.org/resources/platformio-vscode-windows/

## Initial Configuration

Before flashing your robot, look in the config.h file. In here you will find a number of default settings describing things like the motor gear ratio, wheel diameter and wheel spacing. Check that these are at least close to the values required for your robot.

Because it is not possible to know how you wired your motors and ancoders, you will also find defaults for the motor and encoder polarity. You will need to first check  that moving the wheels forwards by hand increases the corresponding encoder count. If not, change the encoder polarity settings as appropriate. If the robot then moves in the wrong direction or just turns instead of moving forward, adjust the relevant otor polarity settings.

## Getting started

There are a number of tests built in to the code. These can be found in tests.cpp. When the controller starts up after power is applied, it will examine the value of the DIP switch at the rear of the robot and decide what to do based on the value it sees.

**The first time you start the robot, make sure that switches are set to zero**. That is, all the switches should be 'down' towards the rear of the robot. Now connect the serial monotor at 115200 baud. When the robot boots, you should see 'OK' written to the monitor.

Most of the tests are activated by first pressing the user button and then bringing your hand close to the front sensor and away again. This is a convenient way to start an action without disturbing the robot. Before that will work, you must calibrate the sensor response. The instructions for that, and the other tests are in the README.MD file found in the code folder.

Run the tests in numerical order after reading the README file and the comments in tests.cpp. The tests work through the features of the hardware and software. By the time you get to the end, you should have some confidence that all is working as it should and you will also have seen examples of how to perform some tasks with the robot.

## Extending the code

At the time of writing, most of the building blocks needed by a maze-solving micromouse are already present. All, that is, except how to actually complete the maze. Those features will come soon enough and the project will contain a complete wall-following and maze solving implementation. Natuarally, there will be considerable scope for improvement by individual users and only the basic features will be included here.

Meanwhile, you can add your own tests and examples by writing code in user.cpp To activate that file, you will need to go back to the config.h file and find, at the top of the file, the line

    const bool USER_MODE = false;

Change this so that ```USER_MODE``` is ```true``` and the code will use the switch values to select an option from user.cpp instead of tests.cpp. You cannot run both so you might like to copy some functions from tests.cpp into user.cpp.

## Updates

Be aware that, if you download a newer copy of the code, and simply unpack it into te same folder, you will over-write config.h, user.h and user.cpp and your changes will be lost. don't do that.

This is an early release of the code and you can expect several updates.

## Contributing

If you have any thoughts about the code, suggestions for changes or improvements, please use the github issues mechanism so that other users can benefit from your observations. Those other users may also be able to offer assistance if the author(s) are not available.

