#include <iostream>
#include <string>
#include <pigpio.h>
#include <unistd.h>

#include "../lib/Servo.h"

int main() {
    Servo servo;

    servo.start();
    return 0;
}


