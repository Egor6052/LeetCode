#include <iostream>
#include <fstream>
#include <cstdlib>

bool isAnalyzerAvailable() {
    return std::system("command -v analyzer > /dev/null 2>&1") == 0;
}

void decodeCANFile(const std::string& inputFile, const std::string& outputFile) {
    if (!isAnalyzerAvailable()) {
        std::cerr << "Помилка: analyzer не знайдено в системі" << std::endl;
        return;
    }

    std::string command = "analyzer -json < " + inputFile + " > " + outputFile;
    int result = std::system(command.c_str());

    if (result != 0) {
        std::cerr << "Помилка виконання analyzer" << std::endl;
    } else {
        std::cout << "Розшифровані дані записані у " << outputFile << std::endl;
    }
}

int main() {
    std::string inputFile = "../formatted1.log";
    std::string outputFile = "../decoded.json";

    decodeCANFile(inputFile, outputFile);

    return 0;
}
