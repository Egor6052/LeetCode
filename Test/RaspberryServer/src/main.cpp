#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
#include <pistache/endpoint.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <sys/socket.h>
#include <net/if.h>
#include <unistd.h>
#include <cstring>

using namespace Pistache;

// Функція відправки CAN-повідомлення
bool sendCanMessage(const std::string& data) {
    int socketCan = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    if (socketCan < 0) {
        std::cerr << "Помилка створення сокету CAN!" << std::endl;
        return false;
    }

    struct ifreq ifr;
    strcpy(ifr.ifr_name, "can0");
    ioctl(socketCan, SIOCGIFINDEX, &ifr);

    struct sockaddr_can addr;
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    if (bind(socketCan, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        std::cerr << "Помилка прив’язки до can0!" << std::endl;
        close(socketCan);
        return false;
    }

    struct can_frame frame;
    frame.can_id = 0x123;
    frame.can_dlc = std::min((int)data.size(), 8);

    memcpy(frame.data, data.c_str(), frame.can_dlc);

    if (write(socketCan, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
        std::cerr << "Помилка відправки CAN-повідомлення!" << std::endl;
        close(socketCan);
        return false;
    }

    close(socketCan);
    return true;
}

int main() {
    Address addr(Ipv4::any(), Port(5000));
    CanServer server(addr);
    
    server.init();
    server.start();

    return 0;
}
