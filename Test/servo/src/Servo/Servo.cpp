
#include <iostream>
#include <string>
#include "../../lib/Servo.h"

Servo::Servo(){
    this->ip = "192.168.100.1";
    this->remoteUser = "pi";
    this->sshSocket = "/tmp/ssh_control_socket";
}

Servo::~Servo(){   }
