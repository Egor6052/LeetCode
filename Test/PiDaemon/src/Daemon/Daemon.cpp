#include <fstream>
#include <sstream>
#include <unordered_map>

#include "../../lib/Daemon.h"

Daemon::Daemon() {
    this->servicePath = "/etc/systemd/system/PiDaemon.service";
    this->configFilePath = "../../configurations/configFile.conf";
    this->apiGetJson = "http://192.168.100.1:3000/signalk/v1/api/sources";

    this->timeout = 20000;
    
    // Default value
    this->can_path = "/dev/can0";
    this->seakeeperSystemAll = 26;
    this->seakeeperGyroStab = 25;
    this->ing_left_power = 24;
    this->ing_right_power = 23;
    this->engine_right = 22;
    this->engine_left = 21;
    this->trim_left_engine_UP = 20;
    this->trim_left_engine_DOWN = 19;
    this->trim_right_engine_UP = 18;
    this->trim_right_engine_DOWN = 17;
    this->trim_general_UP = 16;
    this->trim_general_DOWN = 15;
    this->starlink_On_Off = 14;
    this->kamet_On_Off = 13;

     // Status buttons
    seakeeperSystemAll_status = false;
    seakeeperGyroStab_status = false;
    ing_left_power_status = false;
    ing_right_power_status = false;
    engine_right_status = false;
    engine_left_status = false;
    trim_left_engine_UP_status = false;
    trim_left_engine_DOWN_status = false;
    trim_right_engine_UP_status = false;
    trim_right_engine_DOWN_status = false;
    trim_general_UP_status = false;
    trim_general_DOWN_status = false;
    starlink_On_Off_status = false;
    kamet_On_Off_status = false;

    // File dump names
    seakeeperSystemAll_on_dump = "seakeeperSystemAll_on.dump";
    seakeeperSystemAll_off_dump = "seakeeperSystemAll_off.dump";

    seakeeperGyroStab_on_dump = "seakeeperGyroStab_on.dump";
    seakeeperGyroStab_off_dump = "seakeeperGyroStab_off.dump";

    ing_left_power_on_dump = "ing_left_power_on.dump";
    ing_left_power_off_dump = "ing_left_power_off.dump";

    ing_right_power_on_dump = "ing_right_power_on.dump";
    ing_right_power_off_dump = "ing_right_power_off.dump";

    engine_right_on_dump = "engine_right_on.dump";
    engine_right_off_dump = "engine_right_off.dump";

    engine_left_on_dump = "engine_left_on.dump";
    engine_left_off_dump = "engine_left_off.dump";

    trim_left_engine_UP_on_dump = "trim_left_engine_UP_on.dump";
    trim_left_engine_UP_off_dump = "trim_left_engine_UP_off.dump";

    trim_left_engine_DOWN_on_dump = "trim_left_engine_DOWN_on.dump";
    trim_left_engine_DOWN_off_dump = "trim_left_engine_DOWN_off.dump";

    trim_right_engine_UP_on_dump = "trim_right_engine_UP_on.dump";
    trim_right_engine_UP_off_dump = "trim_right_engine_UP_off.dump";

    trim_right_engine_DOWN_on_dump = "trim_right_engine_DOWN_on.dump";
    trim_right_engine_DOWN_off_dump = "trim_right_engine_DOWN_off.dump";

    trim_general_UP_on_dump = "trim_general_UP_on.dump";
    trim_general_UP_off_dump = "trim_general_UP_off.dump";

    trim_general_DOWN_on_dump = "trim_general_DOWN_on.dump";
    trim_general_DOWN_off_dump = "trim_general_DOWN_off.dump";

    starlink_On_Off_on_dump = "starlink_On_Off_on.dump";
    starlink_On_Off_off_dump = "starlink_On_Off_off.dump";

    kamet_On_Off_on_dump = "kamet_On_Off_on.dump";
    kamet_On_Off_off_dump = "kamet_On_Off_off.dump";

    Configuration();
}

Daemon::~Daemon() {
    gpioTerminate();
}
