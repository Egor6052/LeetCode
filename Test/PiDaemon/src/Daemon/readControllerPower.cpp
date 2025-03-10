#include <pigpio.h>
#include <iostream>
#include <string.h>

#include "../../lib/Daemon.h"

void Daemon::readControllerPowerGPIO(int pin) {
    // Ініціалізація бібліотеки pigpio
    if (gpioInitialise() < 0) {
        std::cerr << "Error initializing pigpio." << std::endl;
        return;
    }

    // statusPower =  gpioRead(pin);
    
    // Настроювання піну на вивід
    gpioSetMode(pin, PI_OUTPUT);

    // TODO
    statusPower = !statusPower;

    gpioWrite(pin, statusPower);

    std::cout << "Gyro Controller GPIO pin" << pin << " is " << statusPower << std::endl;

    gpioTerminate();
}

std::string Daemon::printStatusGyroController(){
    std::string print = "Gyro Controller GPIO pin" + std::to_string(pinGPIO) + " is " + std::to_string(statusPower);
    return print;
}
