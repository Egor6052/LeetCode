#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cstdint>

struct CANMessage {
    double timestamp;
    uint32_t can_id;
    bool extended; // true - 29-bit, false - 11-bit
    std::vector<uint8_t> data;
};

// Функція для парсингу рядка
bool parseLogLine(const std::string& line, CANMessage& msg) {
    std::istringstream ss(line);
    char temp;
    std::string can_id_str, hex_data;

    // Читаємо рядок у форматі: (timestamp) can0 CAN_ID#DATA
    if (!(ss >> temp >> msg.timestamp >> temp >> can_id_str))
        return false;

    size_t hash_pos = can_id_str.find('#');
    if (hash_pos == std::string::npos)
        return false;

    msg.can_id = std::stoul(can_id_str.substr(0, hash_pos), nullptr, 16);
    msg.extended = (can_id_str.substr(0, 3) == "000"); // 29-бітний ID має 3+ leading нулі

    // Читаємо HEX-дані
    if (!(ss >> hex_data))
        return false;

    for (size_t i = 0; i < hex_data.length(); i += 2) {
        msg.data.push_back(std::stoul(hex_data.substr(i, 2), nullptr, 16));
    }
    return true;
}

// Основна функція
void processLogFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Помилка відкриття файлу: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        CANMessage msg;
        if (parseLogLine(line, msg)) {
            std::cout << "Timestamp: " << msg.timestamp
                    << ", CAN ID: " << std::hex << std::setw(8) << std::setfill('0') << msg.can_id
                    << (msg.extended ? " (29-bit)" : " (11-bit)")
                    << ", Data: ";

            for (uint8_t byte : msg.data)
                std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)byte << " ";

            std::cout << std::endl;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Використання: " << argv[0] << " ../2trim_up.log" << std::endl;
        return 1;
    }

    processLogFile(argv[1]);
    return 0;
}
