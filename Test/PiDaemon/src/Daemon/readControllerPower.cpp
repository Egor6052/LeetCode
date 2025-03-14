#include <pigpio.h>
#include <iostream>
#include <string.h>

#include "../../lib/Daemon.h"

// #define STATUS_PIN 26

// void Daemon::readControllerPowerGPIO() {

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
//     seakeeperSystemAll_status = !seakeeperSystemAll_status;

//     gpioWrite(STATUS_PIN, seakeeperSystemAll_status ? 1 : 0);

//     std::cout << "Gyro Controller GPIO pin 13 is " << seakeeperSystemAll_status << std::endl;
// }

std::string Daemon::printStatusGyroController(int status_pin){
    std::string print = "Gyro Controller GPIO pin" + std::to_string(status_pin) + " is " + std::to_string(seakeeperSystemAll_status);
    return print;
}
