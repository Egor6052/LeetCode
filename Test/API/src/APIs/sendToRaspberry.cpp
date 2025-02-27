#include <iostream>
#include <cstdlib>
#include <string>
#include <sys/stat.h>
#include <thread>
#include "../../lib/API.h"

void API::sendToRaspberry() {
    std::string remoteUser = "pi";
    std::string sshSocket = "/tmp/ssh_control_socket";
    std::string right = "right.sh";
    std::string left = "left.sh";
    struct stat buffer;

    // Перевіряємо, чи існує SSH-сокет
    bool socketExists = (stat(sshSocket.c_str(), &buffer) == 0);

    if (!socketExists) {
        std::string startSSH = "ssh -M -S " + sshSocket + " -o ControlPersist=600 -f -N " + remoteUser + "@" + ip;
        std::cout << "\033[1m\033[34mЗапуск SSH-з'єднання: \033[0m" << startSSH << std::endl;
        int result = system(startSSH.c_str());
        if (result != 0) {
            std::cerr << "Помилка запуску SSH-з'єднання! Код: " << result << std::endl;
            return;
        }
    }

    std::string direction, sshCommand;

    sshCommand = "ssh -S " + sshSocket + " " + remoteUser + "@" + ip + " 'bash /home/pi/commands/right.sh'";
    std::cout << "Виконання команди: " << sshCommand << std::endl;
    int result = system(sshCommand.c_str());
    if (result != 0) {
        std::cerr << "Помилка виконання команди! Код: " << result << std::endl;
    }

    while (true) {
        std::cout << "\033[1m\033[31mEnter direction (A/D): \033[0m";
        direction = getChar();

        if (direction == "A" || direction == "a") {
            std::cout << "\033[1m\033[32mВиконуємо left.sh...\033[0m" << std::endl;
            sshCommand = "ssh -S " + sshSocket + " " + remoteUser + "@" + ip + " 'bash /home/pi/commands/" + left + "'";
        } else if (direction == "D" || direction == "d") {
            std::cout << "\033[1m\033[32mВиконуємо right.sh...\033[0m" << std::endl;
            sshCommand = "ssh -S " + sshSocket + " " + remoteUser + "@" + ip + " 'bash /home/pi/commands/" + right + "'";
        } else {
            std::string closeSSH = "ssh -S " + sshSocket + " -O exit " + remoteUser + "@" + ip;
            std::cout << "\033[1m\033[32mЗакриття SSH-з'єднання: \033[0m" << closeSSH << std::endl;
            system(closeSSH.c_str());
            break;
        }

        std::cout << "Виконання команди: " << sshCommand << std::endl;
        result = system(sshCommand.c_str());
        if (result != 0) {
            std::cerr << "Помилка виконання команди! Код: " << result << std::endl;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
