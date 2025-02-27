#include <iostream>
#include <string>
#include <cstdlib>
#include <string>
#include <sys/stat.h>
#include <thread>
#include "../../lib/Servo.h"


void Servo::connection(){
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
}
