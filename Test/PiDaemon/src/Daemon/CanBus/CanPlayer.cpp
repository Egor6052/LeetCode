#include <iostream>
#include <fstream>
#include <fcntl.h>
#include <unistd.h>

#include "../../lib/Daemon.h"

void Daemon::CanPlayer(std::string nameFile) {
        printf("CanPlayer!\n");
        std::string filename = "../../../commands/" + nameFile;

        std::ifstream file(filename, std::ios::binary);
        if (!file.is_open()) {
                std::cerr << "Error opening file: " << filename << std::endl;
                logError("Error opening file: ");
                return;
        }

        int can_fd = open(can_path.c_str(), O_WRONLY);
        if (can_fd < 0) {
                std::cerr << "Error opening CAN interface: " << can_path << std::endl;
                logError("Error opening CAN interface: " + can_path);
                return;
        }

        char buffer[256];
        while (file.read(buffer, sizeof(buffer))) {
                write(can_fd, buffer, file.gcount());
        }
        write(can_fd, buffer, file.gcount());

        close(can_fd);
        file.close();
}
