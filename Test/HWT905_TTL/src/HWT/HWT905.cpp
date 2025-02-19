#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

#include "../../lib/HWT905.h"

HWT905::HWT905(){
    this->name = "HWT905";
    this->serialPort = "/dev/ttyUSB0";
    this->data = "";
    this->time = "";
}

HWT905::~HWT905(){

}

std::string HWT905::getCurrentDateTime() {
    std::time_t now = std::time(nullptr);
    std::tm* tm_now = std::localtime(&now);
    std::ostringstream oss;
    oss << std::put_time(tm_now, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}


void HWT905::stream(){
    std::ifstream serial(serialPort);
    if (!serial.is_open()) {
        std::cerr << "Port not open!" << std::endl;
    }

    while (getline(serial, data)) {
        std::cout << getCurrentDateTime() << std::endl;
        std::cout << "Received: " << data << std::endl;
    }
}

// 0x55 ID PAYLOAD CHECKSUM