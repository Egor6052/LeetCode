#include <iostream>
#include <string>
#include <pigpio.h>
#include <unistd.h>
#include "../../lib/Servo.h"

void Servo::start() {
    connection();

    // if (gpioInitialise() < 0) {
    //     std::cerr << "Помилка ініціалізації GPIO!" << std::endl;
    //     return;
    // }

    // Частота 50 Гц
    // gpioSetPWMfrequency(SERVO_PIN, 50);

    int angle;
    while (true) {
        std::cout << "Введіть кут (0-180): ";
        std::cin >> angle;
        if (angle < 0 || angle > 180) {
            std::cerr << "Некоректний кут!" << std::endl;
            continue;
        }

        setServoAngle(angle);
        // оновлення сигналу (цикл 50 Гц)
        usleep(50000);
    }

    gpioServo(SERVO_PIN, 0);
    gpioTerminate();
}
