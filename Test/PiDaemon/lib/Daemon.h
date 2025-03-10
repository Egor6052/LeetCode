#pragma once

#include <iostream>
#include <string.h>

class Daemon {
    private:
        // "/etc/systemd/system/PiDaemon.service"
        std::string servicePath;
        // For logging
        std::string apiGetJson;

        // Gpio pin to reed status
        int pinGPIO;

        bool statusPower;
        bool statusGyro;

    public:
        Daemon();
        ~Daemon();

        std::string getCurrentDateTime();

        // Adding to autostart
        void addToStartup();
        // Remove from autostart
        void removeFromAutostart();

        void gyroControllerOn();
        void gyroControllerOff();

        void toggleGyroController();

        void readControllerPowerGPIO(int pin);
        std::string printStatusGyroController();

        std::string getJSON();
        std::string loggerStateInfo();
};
