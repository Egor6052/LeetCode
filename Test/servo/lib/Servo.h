#pragma once
#include <iostream>
#include <string>

  // GPIO2 (Physical pin 3)
#define SERVO_PIN 2

class Servo {
    private:
        std::string remoteUser;
        std::string ip;
        std::string sshSocket;
    
    public:
        Servo();
        ~Servo();

        void connection();
        void start();
        void setServoAngle(int angle);
};
