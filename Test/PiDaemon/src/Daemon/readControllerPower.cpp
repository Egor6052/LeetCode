#include <pigpio.h>
#include <iostream>
#include <string.h>

#include "../../lib/Daemon.h"

#define STATUS_PIN 26

void Daemon::readControllerPowerGPIO() {

//     static bool initialized = false;
//     if (!initialized) {
//         if (gpioInitialise() < 0) {
//             std::cerr << "Error initializing pigpio." << std::endl;
//             return;
//         }
//         initialized = true;
//     }

//     gpioSetMode(STATUS_PIN, PI_OUTPUT);

//     // TODO
//     statusPower = !statusPower;

//     gpioWrite(STATUS_PIN, statusPower ? 1 : 0);

//     std::cout << "Gyro Controller GPIO pin 13 is " << statusPower << std::endl;
}

std::string Daemon::printStatusGyroController(){
    std::string print = "Gyro Controller GPIO pin" + std::to_string(STATUS_PIN) + " is " + std::to_string(statusPower);
    return print;
}
