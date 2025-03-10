#include <iostream>
#include <string.h>
#include "../lib/Daemon.h"

int main(){
    std::cout << "\033[1m\033[32mServise is start!\033[0m" << std::endl;

    Daemon daemon;
    daemon.addToStartup();
    // daemon.removeFromAutostart();

    daemon.toggleGyroController();

    daemon.loggerStateInfo();
    return 0;
}
