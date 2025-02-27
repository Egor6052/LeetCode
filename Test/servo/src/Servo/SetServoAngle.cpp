
#include <iostream>
#include <string>
#include <pigpio.h>
#include <unistd.h>
#include "../../lib/Servo.h"

void Servo::setServoAngle(int angle) {
    // обчислення ширини імпульсу для керування сервоприводом через PWM-сигнал.
    // 500 — мінімальна ширина імпульсу (500 мкс) для кута 0°.
    // pulseLength — діапазон зміни ширини імпульсу (від 500 до 2500 мкс).
    // 180 — нормалізація значення на діапазон 0–180 градусів.

    int pulseLength = 2000;
    int pulseWidth = 500 + (angle * pulseLength) / 180;    
    
    std::string sshCommand = "ssh -S " + sshSocket + " " + remoteUser + "@" + ip + " 'pigs s " + std::to_string(SERVO_PIN) + " " + std::to_string(pulseWidth) + "'";
    
    int result = system(sshCommand.c_str());
    if (result != 0) {
        std::cerr << "Помилка керування серво через SSH!" << std::endl;
    }
}