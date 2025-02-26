#include <iostream>
#include <cstdlib>
#include <string>
#include <sys/stat.h>
#include "../../lib/API.h"

void API::sendToRaspberry() {
    std::string remoteUser = "pi";  
    std::string sshSocket = "/tmp/ssh_control_socket";
    std::string right = "right.sh";
    std::string left = "left.sh";
    struct stat buffer;

    // Перевіряємо, чи вже є відкрите SSH-з'єднання
    if (stat(sshSocket.c_str(), &buffer) != 0) {
        std::string startSSH = "ssh -M -S " + sshSocket + " -o ControlPersist=600 -f -N " + remoteUser + "@" + ip;
        if (system(startSSH.c_str()) != 0) {
            std::cerr << "Помилка запуску SSH-з'єднання!" << std::endl;
            return;
        }
    }

    std::string direction, sshCommand;
    while (true) {
        std::cout << "Enter direction (A/D): ";
        std::cin >> direction;

        if (direction == "A" || direction == "a") {
            std::cout << "Виконуємо left.sh..." << std::endl;
            sshCommand = "ssh -S " + sshSocket + " " + remoteUser + "@" + ip + " 'bash /home/pi/commands/" + left + "'";
        }
        else if (direction == "D" || direction == "d") {
            std::cout << "Виконуємо right.sh..." << std::endl;
            sshCommand = "ssh -S " + sshSocket + " " + remoteUser + "@" + ip + " 'bash /home/pi/commands/" + right + "'";
        } 
        // else {
        //     break;
        // }
    }

    std::string closeSSH = "ssh -S " + sshSocket + " -O exit " + remoteUser + "@" + ip;
    system(closeSSH.c_str());
}
