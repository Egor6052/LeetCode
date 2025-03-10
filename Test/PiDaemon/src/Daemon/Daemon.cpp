#include "../../lib/Daemon.h"

Daemon::Daemon(){
    this->servicePath = "/etc/systemd/system/PiDaemon.service";
    this->apiGetJson = "http://192.168.100.1:3000/signalk/v1/api/sources";
    this->pinGPIO = 26;
    this->statusPower = false;
    this->statusGyro = false;
}

Daemon::~Daemon(){  }

