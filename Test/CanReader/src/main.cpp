#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdint>

#include "../lib/CanFile.h"

int main() {
    // std::string filename = "../2trim_up.dump";
    std::vector<CANMessage> messages = parseCANDump(filename);

    for (const auto& msg : messages) {
        std::cout << "Timestamp: " << msg.timestamp << " ID: " << std::hex << msg.id << " Data: ";
        for (uint8_t byte : msg.data) {
            std::cout << std::hex << static_cast<int>(byte) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
