#include <iostream>
#include "../lib/Boat.h"

int main() {
    Boat boat1;
    std::cout << "Default Boat Info:" << std::endl;
    boat1.printInfo();
    std::cout << "\n";

    Boat Boat2;
    Boat2.setIP("198.0.0.1");
    Boat2.setName("Sea Explorer");
    Boat2.setLength(15.5);
    Boat2.setSpeed(25.0);
    Boat2.setCapacity(10);

    std::cout << "Boat Info:" << std::endl;
    Boat2.printInfo();

    Boat2.setCanInterface("can0");
    Boat2.setSock();
    std::cout << "Слухаємо CAN-шину (" << Boat2.getCanInterface() << ")..." << std::endl;
    Boat2.listen_can_messages();

    return 0;
}
