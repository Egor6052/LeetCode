#include <iostream>
#include <string>
#include "../lib/API.h"

int main() {
    // API api;
    // api.stream();

    API app;

    // app.setJsonPath("../candump-2025-02-26_150127.log");
    std::cout << "\033[1m\033[31m" << std::endl;
    app.sendToRaspberry();
    std::cout << "\033[0m" << std::endl;
    app.logData();


    return 0;
}
