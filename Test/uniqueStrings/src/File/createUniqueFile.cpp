#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <sstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <unordered_map>

#include "../../lib/File.h"

void File::createUniqueFile() {

    // Створення директорії "output", якщо вона не існує
    // struct stat info;
    // if (stat("../../output", &info) != 0) {
    //     if (mkdir("../../output", 0777) != 0) {
    //         std::cerr << "Помилка створення директорії 'output'" << std::endl;
    //         return;
    //     }
    // }

    std::ifstream inputFile(pathToFile);
    if (!inputFile.is_open()) {
        std::cerr << "Could not open file.: " << pathToFile << std::endl;
        return;
    }

    std::ofstream outputFile(newFileName);
    if (!outputFile.is_open()) {
        std::cerr << "Failed to create source file" << std::endl;
        return;
    }

    std::unordered_map<std::string, std::string> uniqueIdMap;
    std::unordered_map<std::string, int> countMap;
    std::string line;

    // Перший прохід: підраховуємо кількість повторень повних ідентифікаторів
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string timestamp, can, identifier;

        if (iss >> timestamp >> can >> identifier) {
            countMap[identifier]++;
            uniqueIdMap[identifier] = line;
        }
    }

    inputFile.close();

    // Другий прохід: записуємо унікальні рядки за повними ідентифікаторами
    for (const auto& [id, cnt] : countMap) {
        if (cnt == 1) {
            outputFile << uniqueIdMap[id] << std::endl;
        }
    }

    std::cout << "Filtration complete!\nOutput file: " << "\033[1m\033[32m" << newFileName << "\033[0m" << std::endl;

    printFileContents(newFileName);
    std::cout << std::endl;

}