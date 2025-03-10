#include <iostream>
#include <cstdio>
#include <memory>
#include <array>
#include <pigpio.h>

#include "../../lib/Daemon.h"

void Daemon::gyroControllerOn() {
    if (statusPower){
        std::cout << "Gyro is ON!" << std::endl;
    } else {
        // const char* command = "cat ../../commands/gyro/gyro_on.dump | canplayer";
    
        // // Opening the process for reading
        // std::array<char, 128> buffer;
        // std::string result;
        // FILE* pipe = popen(command, "r");

        // if (!pipe) {
        //     std::cerr << "Error opening pipe!" << std::endl;
        //     return;
        // }

        // // Read the command output
        // while (fgets(buffer.data(), buffer.size(), pipe) != nullptr) {
        //     result += buffer.data();
        // }

        // // Close the pipe and get the completion code
        // int exitCode = pclose(pipe);

        // if (exitCode == 0) {
        //     std::cout << "Gyro is Enable!\n" << result << std::endl;
        // } else {
        //     std::cerr << "Error executing gyro command. Exit code: " << exitCode << std::endl;
        // }

        readControllerPowerGPIO(pinGPIO);
    }
}
