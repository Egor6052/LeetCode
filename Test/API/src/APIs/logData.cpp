
#include <iostream>
#include <fstream>
#include <filesystem>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include "../../lib/API.h"

void API::logData() {
    std::string response = getJSON();

    if (response.find("Помилка") == 0) {
        std::cerr << response << std::endl;
        return;
    }

    std::string directoryPath = "../logs/";
    std::filesystem::create_directories(directoryPath);

    if (!std::filesystem::exists(directoryPath)) {
        std::cerr << "Помилка: не вдалося створити каталог " << directoryPath << std::endl;
        return;
    }

    std::string filePath = directoryPath + getCurrentDateTime() + ".json";

    std::ofstream outFile(filePath);
    if (!outFile.is_open()) {
        std::cerr << "Помилка: не вдалося створити файл " << filePath << std::endl;
        return;
    }

    outFile << response;
    outFile.close();
    
    std::cout << "\033[1m\033[31mДані успішно збережено у: " << filePath << "\033[0m" << std::endl;
}
