#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <sys/socket.h>
#include <net/if.h>
#include <iostream>
#include "../../lib/Boat.h"

void Boat::listen_can_messages() {
    struct can_frame frame;

    while (true) {
        ssize_t bytes_read = read(sock, &frame, sizeof(frame));
        if (bytes_read < 0) {
            perror("Помилка читання CAN");
            break;
        }

        if ((frame.can_id & CAN_EFF_MASK) == PGN_AUTOPILOT) {  
            uint16_t heading_raw = frame.data[0] | (frame.data[1] << 8);
            double heading = heading_raw / 100.0;  

            std::cout << "Отримано команду автопілота: " << heading << "°" << std::endl;

            // Модифікуємо команду (+10°)
            send_autopilot_command(heading + 10);
        }
    }
}