#include <iostream>
#include <string.h>
#include "../lib/File.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Використання: " << argv[0] << " <шлях_до_файлу>" << std::endl;
        return 1;
    }

    std::string filePath = argv[1];

    File file;
    file.setPathToFile(filePath);
    file.createUniqueFile();

    return 0;
}
