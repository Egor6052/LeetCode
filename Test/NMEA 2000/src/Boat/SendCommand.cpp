#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <sys/socket.h>
#include <net/if.h>
#include <iostream>
#include "../../lib/Boat.h"

void Boat::send_autopilot_command(double heading) {
    struct can_frame frame = {};
    // Extended frame format (29-бітний ID)
    frame.can_id = PGN_AUTOPILOT | CAN_EFF_FLAG;
    // Довжина повідомлення (NMEA 2000 використовує 8 байтів)
    frame.can_dlc = 8;

    // Перетворюємо в цілі градуси
    uint16_t heading_int = static_cast<uint16_t>(heading * 100);
    frame.data[0] = heading_int & 0xFF;
    frame.data[1] = (heading_int >> 8) & 0xFF;

    if (write(sock, &frame, sizeof(frame)) != sizeof(frame)) {
        perror("Помилка відправки CAN повідомлення");
    } else {
        std::cout << "Відправлено команду: " << heading << "°" << std::endl;
    }
}