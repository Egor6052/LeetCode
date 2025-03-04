#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cstdint>

struct CANMessage {
    double timestamp;
    uint32_t pgn;
    uint8_t source_address;
    uint8_t priority;
    std::vector<uint8_t> data;
};

// Функція для парсингу рядка лог-файлу
bool parseLogLine(const std::string& line, CANMessage& msg) {
    std::istringstream ss(line);
    char temp;
    std::string can_id, hex_data;

    // Зчитуємо рядок у форматі: (timestamp) can0 ID#DATA
    if (!(ss >> temp >> msg.timestamp >> temp >> can_id))
        return false;

    size_t hash_pos = can_id.find('#');
    if (hash_pos == std::string::npos)
        return false;

    uint32_t can_id_val = std::stoul(can_id.substr(0, hash_pos), nullptr, 16);
    msg.pgn = (can_id_val >> 8) & 0xFFFF;  // PGN (Parameter Group Number)
    msg.source_address = can_id_val & 0xFF; // Source Address
    msg.priority = (can_id_val >> 26) & 0x7; // Priority (3 біти)

    // Зчитуємо дані після `#`
    if (!(ss >> hex_data))
        return false;

    // Конвертуємо дані з hex-рядка у байти
    for (size_t i = 0; i < hex_data.length(); i += 2) {
        msg.data.push_back(std::stoul(hex_data.substr(i, 2), nullptr, 16));
    }

    return true;
}

// Основна функція для читання лог-файлу та виводу розшифрованих повідомлень
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
                    << ", PGN: " << std::hex << std::setw(4) << std::setfill('0') << msg.pgn
                    << ", Source: " << std::hex << std::setw(2) << std::setfill('0') << (int)msg.source_address
                    << ", Priority: " << (int)msg.priority
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
