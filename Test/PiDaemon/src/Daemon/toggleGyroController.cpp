#include <iostream>
#include <thread>
#include <pigpio.h>

#include "../../lib/Daemon.h"

// Запусти pigpio-демон
// sudo pigpiod 

// Встанови GPIO26 (пін 30) у вихідний режим
// pigs m 26 1

// On
// pigs w 26 1 

// Off
// pigs w 26 0

void Daemon::toggleGyroController(){
    bool OnOff = false;

    // Initialize pigpio
    if (gpioInitialise() < 0) {
        std::cerr << "Error initializing pigpio." << std::endl;
        return;
    }

    std::cout << "pigpio is initialized!" << std::endl;

    while (true) {
        
        OnOff = gpioRead(pinGPIO);

        std::cout << "GPIO " << pinGPIO << " state: " << OnOff << std::endl;

        if (OnOff && !statusPower) {
            gyroControllerOn();
            printf("\n");
            
            if (!statusPower) {
                statusPower = !statusPower;
            }
            std::cout << printStatusGyroController() << std::endl;


        } else if (!OnOff && statusPower) {
            gyroControllerOff();
            printf("\n");

            if (statusPower) {
                statusPower = !statusPower;
            }
            std::cout << printStatusGyroController() << std::endl;

        }

        // Wait
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    }

}
