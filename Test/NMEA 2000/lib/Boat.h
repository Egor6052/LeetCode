#pragma once
#ifndef BOAT_H
#define BOAT_H

#include <iostream>
#include <string.h>

class Boat {
    private:
        std::string ipAddress;
        std::string name;
        float length;
        float speed;
        int capacity;

        std::string can_interface;
        int sock;
        
    public:
        Boat();
        ~Boat();

        void setIP(const std::string& valueIP);
        void setName(const std::string& valueName);
        void setLength(float valueLength);
        void setSpeed(float valueSpeed);
        void setCapacity(int valueCapacity);

        void setCanInterface(const std::string& valueInterface);
        void Boat::setSock();

        std::string getName();
        float getLength();
        float getSpeed();
        int getCapacity();
        std::string getCanInterface();
        int getSock();

        void printInfo();

        void listen_can_messages();
        void send_autopilot_command(double heading);
        int open_can_socket(const char *ifname);

};

#endif