#include <iostream>
#include <string>
#include "../lib/API.h"

int main() {
    // API api;
    // api.stream();

    API uart;
    uart.sendToRaspberry();

    return 0;
}
