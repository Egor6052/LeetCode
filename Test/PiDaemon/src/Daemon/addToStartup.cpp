#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#include "../../lib/Daemon.h"

// sudo systemctl daemon-reload

// sudo systemctl restart PiDaemon.service

// sudo systemctl status PiDaemon.service

// Додавання до автозапуску
void Daemon::addToStartup() {
    if (servicePath.empty()) {
        std::cerr << "Error: servicePath is empty!" << std::endl;
        return;
    }

    std::ofstream serviceFile(servicePath, std::ios::out | std::ios::trunc);
    if (!serviceFile) {
        std::cerr << "Could not open " << servicePath << " for writing." << std::endl;
        return;
    }

    serviceFile << "[Unit]\n";
    serviceFile << "Description=PiDaemon\n";
    serviceFile << "After=network.target\n\n";

    serviceFile << "[Service]\n";
    serviceFile << "ExecStart=/home/pi/Documents/PiDaemon/build/start\n";
    serviceFile << "Restart=always\n";
    serviceFile << "User=root\n";
    serviceFile << "WorkingDirectory=/\n\n";

    serviceFile << "[Install]\n";
    serviceFile << "WantedBy=multi-user.target\n";

    serviceFile.close();

    // Оновлення systemd
    int reloadStatus = system("sudo systemctl daemon-reload");
    if (reloadStatus != 0) {
        std::cerr << "Error: Failed to reload systemd daemon!" << std::endl;
        return;
    }

    // Включення автозапуску
    int enableStatus = system("sudo systemctl enable PiDaemon.service");
    if (enableStatus != 0) {
        std::cerr << "Error: Failed to enable PiDaemon service!" << std::endl;
        return;
    }

    std::cout << "\033[1m\033[33mDaemon added to autostart!\033[0m" << std::endl;
}
