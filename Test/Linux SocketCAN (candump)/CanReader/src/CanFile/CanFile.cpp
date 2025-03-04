// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <vector>
// #include <cstdint>

// #include "../../lib/CanFile.h"

// CanFile::CanFile(){
//     this->filename "../2trim_up.dump";
// }

// struct CANMessage {
//     double timestamp;
//     std::string interface;
//     uint32_t id;
//     std::vector<uint8_t> data;
// }

// std::vector<CANMessage> CanFile::parseCANDump(const std::string& filename) {
//     std::ifstream file(filename);
//     std::vector<CANMessage> messages;
//     std::string line;

//     if (!file) {
//         std::cerr << "Не вдалося відкрити файл: " << filename << std::endl;
//         return messages;
//     }

//     while (std::getline(file, line)) {
//         std::istringstream iss(line);
//         CANMessage msg;
//         std::string id_str, data_str;
//         char hash;

//         if (!(iss >> msg.timestamp >> msg.interface >> id_str)) continue;
//         if (id_str.find('#') == std::string::npos) continue;

//         std::istringstream id_stream(id_str);
//         id_stream >> std::hex >> msg.id >> hash >> data_str;

//         for (size_t i = 0; i < data_str.size(); i += 2) {
//             std::string byte_str = data_str.substr(i, 2);
//             msg.data.push_back(std::stoi(byte_str, nullptr, 16));
//         }

//         messages.push_back(msg);
//     }
//     return messages;
// }