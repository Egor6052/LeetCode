#include <iostream>
#include <string>
#include <fstream>

#include "../../lib/File.h"

void File::printFileContents(std::string filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::cout << "\033[1m\033[33m" << line << "\033[0m" << std::endl;
    }

    file.close();
}