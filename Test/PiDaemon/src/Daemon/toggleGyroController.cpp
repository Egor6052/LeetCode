#include <iostream>
#include <thread>
#include <pigpio.h>

#include "../../lib/Daemon.h"

void Daemon::toggleGyroController(){

    // Initialize pigpio
    if (gpioInitialise() < 0) {
        std::cerr << "Error initializing pigpio." << std::endl;
        logError("Error initializing pigpio.");
        return;
    }

    std::cout << "pigpio is initialized!" << std::endl;

    while (true)
    {
        // checking all statuses
        CheckStatus();
        
        // Wait
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    }
}
