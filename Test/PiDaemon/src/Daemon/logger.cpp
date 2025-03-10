#include <iostream>
#include <fstream>
#include <filesystem>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

#include "../../lib/Daemon.h"

std::string Daemon::loggerStateInfo() {
    std::string response = getJSON();

    if (response.find("Error") == 0) {
        std::cerr << response << std::endl;
        return "";
    }

    std::string directoryPath = "../logs/";
    std::filesystem::create_directories(directoryPath);

    if (!std::filesystem::exists(directoryPath)) {
        std::cerr << "Error: file creation catalog " << directoryPath << std::endl;
        return "";
    }

    std::string filePath = directoryPath + getCurrentDateTime() + ".json";

    std::ofstream outFile(filePath);
    if (!outFile.is_open()) {
        std::cerr << "Error: file creation failed " << filePath << std::endl;
        return "";
    }

    std::cout << "\033[1m\033[31mData successfully saved to: " << filePath << "\033[0m" << std::endl;

    outFile << response;
    outFile.close();

    return response;
}
