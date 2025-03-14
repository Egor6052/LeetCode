#include <iostream>
#include <string.h>
#include "../lib/Daemon.h"
#include "../lib/Logger.h"

int main(){
    std::cout << "\033[1m\033[32mServise is start!\033[0m" << std::endl;

    Daemon daemon;
    Logger logger;

    daemon.addToStartup();
    // daemon.removeFromAutostart();
    // daemon.backgroundMode();

    daemon.toggleGyroController();

    std::string log = daemon.getCurrentDateTime();
    logger.logError(log);

    // daemon.loggerStateInfo();
    return 0;
}
