#include "../../lib/Boat.h"
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <sys/socket.h>
#include <net/if.h>

#define PGN_AUTOPILOT 127237

Boat::Boat() {
    this->ipAddress = "198.0.0.0";
    this->name = "Boat1";
    this->length = 0.0f;
    this->speed = 0.0f;
    this->capacity = 0;

    this->can_interface = "can0";
    this->sock = -1;
}

Boat::~Boat() {  
    if (sock > 0) {
        close(sock);
    }
}

void Boat::setIP(const std::string& valueIP) {
    this->ipAddress = valueIP;
}

void Boat::setName(const std::string& valueName) {
    this->name = valueName;
}

void Boat::setLength(float valueLength) {
    this->length = valueLength;
}

void Boat::setSpeed(float valueSpeed) {
    this->speed = valueSpeed;
}

void Boat::setCapacity(int valueCapacity) {
    this->capacity = valueCapacity;
}

void Boat::setCanInterface(const std::string& valueInterface) {
    this->can_interface = valueInterface;
}

void Boat::setSock() {
    this->sock = open_can_socket(can_interface.c_str());
}

std::string Boat::getName() {
    return name; 
}

float Boat::getLength() {
    return length;
}

float Boat::getSpeed() {
    return speed;
}

int Boat::getCapacity() {
    return capacity;
}

std::string Boat::getCanInterface() {
    return can_interface;
}
int Boat::getSock(){
    return sock;
}

void Boat::printInfo() {
    std::cout << "Boat Name: " << name << std::endl;
    std::cout << "Length: " << length << " meters" << std::endl;
    std::cout << "Speed: " << speed << " knots" << std::endl;
    std::cout << "Capacity: " << capacity << " people" << std::endl;
    std::cout << "CAN Interface: " << can_interface << std::endl;
}
