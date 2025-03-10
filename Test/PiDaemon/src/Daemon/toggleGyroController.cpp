#include <iostream>
#include <thread>
#include "../../lib/Daemon.h"

void Daemon::toggleGyroController(){
    std::string OnOff;

    while (true)
    {
        std::cout << "ON / OFF gyro?\n 1 - On; 2 - Off";
        std::cin >> OnOff;
        if (OnOff == "1"){
            gyroControllerOn();
            std::cout << printStatusGyroController() << std::endl;
            printf("\n");
            
            // Затримка
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        } else if (OnOff == "2"){
            gyroControllerOff();
            std::cout << printStatusGyroController() << std::endl;
            printf("\n");
            
            // Затримка
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        } else {
            break;
        }
    }

}