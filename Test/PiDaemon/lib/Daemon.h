#pragma once

#include <iostream>
#include <string.h>
#include <pigpio.h>
#include <unordered_map>

#include "Logger.h"

// #define STATUS_PIN 26

class Daemon : public Logger {
    private:
        std::string servicePath;
        
        // To get values ​​for configuration
        std::string configFilePath;
        std::unordered_map<std::string, std::string> configValues;

        // Logging from API OpenPlotter
        std::string apiGetJson;

         // exit port for can-dumps
        std::string can_path;

        // delay time after switching on seakeeperSystemAll
        int timeout;

        // Status reading pins
        int seakeeperSystemAll;
        int seakeeperGyroStab;
        int ing_left_power;
        int ing_right_power;
        int engine_right;
        int engine_left;
        int trim_left_engine_UP;
        int trim_left_engine_DOWN;
        int trim_right_engine_UP;
        int trim_right_engine_DOWN;
        int trim_general_UP;
        int trim_general_DOWN;
        int starlink_On_Off;
        int kamet_On_Off;

        // Status buttons
        bool seakeeperSystemAll_status;
        bool seakeeperGyroStab_status;
        bool ing_left_power_status;
        bool ing_right_power_status;
        bool engine_right_status;
        bool engine_left_status;
        bool trim_left_engine_UP_status;
        bool trim_left_engine_DOWN_status;
        bool trim_right_engine_UP_status;
        bool trim_right_engine_DOWN_status;
        bool trim_general_UP_status;
        bool trim_general_DOWN_status;
        bool starlink_On_Off_status;
        bool kamet_On_Off_status;

        // File dump names
        std::string seakeeperSystemAll_on_dump;
        std::string seakeeperSystemAll_off_dump;

        std::string seakeeperGyroStab_on_dump;
        std::string seakeeperGyroStab_off_dump;

        std::string ing_left_power_on_dump;
        std::string ing_left_power_off_dump;

        std::string ing_right_power_on_dump;
        std::string ing_right_power_off_dump;

        std::string engine_right_on_dump;
        std::string engine_right_off_dump;

        std::string engine_left_on_dump;
        std::string engine_left_off_dump;

        std::string trim_left_engine_UP_on_dump;
        std::string trim_left_engine_UP_off_dump;

        std::string trim_left_engine_DOWN_on_dump;
        std::string trim_left_engine_DOWN_off_dump;

        std::string trim_right_engine_UP_on_dump;
        std::string trim_right_engine_UP_off_dump;

        std::string trim_right_engine_DOWN_on_dump;
        std::string trim_right_engine_DOWN_off_dump;

        std::string trim_general_UP_on_dump;
        std::string trim_general_UP_off_dump;

        std::string trim_general_DOWN_on_dump;
        std::string trim_general_DOWN_off_dump;

        std::string starlink_On_Off_on_dump;
        std::string starlink_On_Off_off_dump;

        std::string kamet_On_Off_on_dump;
        std::string kamet_On_Off_off_dump;

    public:
        Daemon();
        ~Daemon();

        void Configuration();
        void ConfigFields();

        void CheckStatus();

        std::string getCurrentDateTime();

        // Adding to autostart
        void addToStartup();

        // Remove from autostart
        void removeFromAutostart();
        void toggleGyroController();
        // void readControllerPowerGPIO();

        void CanPlayer(std::string nameFile);

        // void backgroundMode();
        std::string printStatusGyroController(int status_pin);

        // std::string getJSON();
        // std::string loggerStateInfo();
};
