#include <iostream>
#include <thread>
#include <pigpio.h>
#include "../../lib/Daemon.h"

void Daemon::CheckStatus() {

// void CheckStatus(int pin, bool &status, std::string name_dump_on, std::string name_dump_off) {
//     if (gpioRead(pin) && !status) {
//         CanPlayer(name_dump_on);
//         if (!status) {
//             status = !status;
//         }
//     } else if (!gpioRead(pin) && status) {
//         CanPlayer(name_dump_off);
//         if (status) {
//             status = !status;
//         }
//     }
//     std::cout << printStatusGyroController(pin) << std::endl;
// }




    // seakeeperSystemAll
    if (gpioRead(seakeeperSystemAll) && !seakeeperSystemAll_status) {
        CanPlayer(seakeeperSystemAll_on_dump);
        if (!seakeeperSystemAll_status) {
            seakeeperSystemAll_status = !seakeeperSystemAll_status;
        }
        // Wait
        std::this_thread::sleep_for(std::chrono::milliseconds(timeout));
        std::cout << printStatusGyroController(seakeeperSystemAll) << std::endl;
    }
    if (!gpioRead(seakeeperSystemAll) && seakeeperSystemAll_status) {
        CanPlayer(seakeeperSystemAll_off_dump);
        if (seakeeperSystemAll_status) {
            seakeeperSystemAll_status = !seakeeperSystemAll_status;
        }
        std::cout << printStatusGyroController(seakeeperSystemAll) << std::endl;
    }

    // seakeeperGyroStab
    if (gpioRead(seakeeperGyroStab) && !seakeeperGyroStab_status) {
        CanPlayer(seakeeperGyroStab_on_dump);
        if (!seakeeperGyroStab_status) {
            seakeeperGyroStab_status = !seakeeperGyroStab_status;
        }
        std::cout << printStatusGyroController(seakeeperGyroStab) << std::endl;
    }
    if (!gpioRead(seakeeperGyroStab) && seakeeperGyroStab_status) {
        CanPlayer(seakeeperGyroStab_off_dump);
        if (seakeeperGyroStab_status) {
            seakeeperGyroStab_status = !seakeeperGyroStab_status;
        }
        std::cout << printStatusGyroController(seakeeperGyroStab) << std::endl;
    }

    // ing_left_power
    if (gpioRead(ing_left_power) && !ing_left_power_status) {
        CanPlayer(ing_left_power_on_dump);
        if (!ing_left_power_status) {
            ing_left_power_status = !ing_left_power_status;
        }
        std::cout << printStatusGyroController(ing_left_power) << std::endl;
    }
    if (!gpioRead(ing_left_power) && ing_left_power_status) {
        CanPlayer(ing_left_power_off_dump);
        if (ing_left_power_status) {
            ing_left_power_status = !ing_left_power_status;
        }
        std::cout << printStatusGyroController(ing_left_power) << std::endl;
    }

    // ing_right_power
    if (gpioRead(ing_right_power) && !ing_right_power_status) {
        CanPlayer(ing_right_power_on_dump);
        if (!ing_right_power_status) {
            ing_right_power_status = !ing_right_power_status;
        }
        std::cout << printStatusGyroController(ing_right_power) << std::endl;
    }
    if (!gpioRead(ing_right_power) && ing_right_power_status) {
        CanPlayer(ing_right_power_off_dump);
        if (ing_right_power_status) {
            ing_right_power_status = !ing_right_power_status;
        }
        std::cout << printStatusGyroController(ing_right_power) << std::endl;
    }

    // engine_right
    if (gpioRead(engine_right) && !engine_right_status) {
        CanPlayer(engine_right_on_dump);
        if (!engine_right_status) {
            engine_right_status = !engine_right_status;
        }
        std::cout << printStatusGyroController(engine_right) << std::endl;
    }
    if (!gpioRead(engine_right) && engine_right_status) {
        CanPlayer(engine_right_off_dump);
        if (engine_right_status) {
            engine_right_status = !engine_right_status;
        }
        std::cout << printStatusGyroController(engine_right) << std::endl;
    }

    // engine_left
    if (gpioRead(engine_left) && !engine_left_status) {
        CanPlayer(engine_left_on_dump);
        if (!engine_left_status) {
            engine_left_status = !engine_left_status;
        }
        std::cout << printStatusGyroController(engine_left) << std::endl;
    }
    if (!gpioRead(engine_left) && engine_left_status) {
        CanPlayer(engine_left_off_dump);
        if (engine_left_status) {
            engine_left_status = !engine_left_status;
        }
        std::cout << printStatusGyroController(engine_left) << std::endl;
    }

    // trim_left_engine_UP
    if (gpioRead(trim_left_engine_UP) && !trim_left_engine_UP_status) {
        CanPlayer(trim_left_engine_UP_on_dump);
        if (!trim_left_engine_UP_status) {
            trim_left_engine_UP_status = !trim_left_engine_UP_status;
        }
        std::cout << printStatusGyroController(trim_left_engine_UP) << std::endl;
    }
    if (!gpioRead(trim_left_engine_UP) && trim_left_engine_UP_status) {
        CanPlayer(trim_left_engine_UP_off_dump);
        if (trim_left_engine_UP_status) {
            trim_left_engine_UP_status = !trim_left_engine_UP_status;
        }
        std::cout << printStatusGyroController(trim_left_engine_UP) << std::endl;
    }

    // trim_left_engine_DOWN
    if (gpioRead(trim_left_engine_DOWN) && !trim_left_engine_DOWN_status) {
        CanPlayer(trim_left_engine_DOWN_on_dump);
        if (!trim_left_engine_DOWN_status) {
            trim_left_engine_DOWN_status = !trim_left_engine_DOWN_status;
        }
        std::cout << printStatusGyroController(trim_left_engine_DOWN) << std::endl;
    }
    if (!gpioRead(trim_left_engine_DOWN) && trim_left_engine_DOWN_status) {
        CanPlayer(trim_left_engine_DOWN_off_dump);
        if (trim_left_engine_DOWN_status) {
            trim_left_engine_DOWN_status = !trim_left_engine_DOWN_status;
        }
        std::cout << printStatusGyroController(trim_left_engine_DOWN) << std::endl;
    }

    // trim_right_engine_UP
    if (gpioRead(trim_right_engine_UP) && !trim_right_engine_UP_status) {
        CanPlayer(trim_right_engine_UP_on_dump);
        if (!trim_right_engine_UP_status) {
            trim_right_engine_UP_status = !trim_right_engine_UP_status;
        }
        std::cout << printStatusGyroController(trim_right_engine_UP) << std::endl;
    }
    if (!gpioRead(trim_right_engine_UP) && trim_right_engine_UP_status) {
        CanPlayer(trim_right_engine_UP_off_dump);
        if (trim_right_engine_UP_status) {
            trim_right_engine_UP_status = !trim_right_engine_UP_status;
        }
        std::cout << printStatusGyroController(trim_right_engine_UP) << std::endl;
    }

    // trim_right_engine_DOWN
    if (gpioRead(trim_right_engine_DOWN) && !trim_right_engine_DOWN_status) {
        CanPlayer(trim_right_engine_DOWN_on_dump);
        if (!trim_right_engine_DOWN_status) {
            trim_right_engine_DOWN_status = !trim_right_engine_DOWN_status;
        }
        std::cout << printStatusGyroController(trim_right_engine_DOWN) << std::endl;
    }
    if (!gpioRead(trim_right_engine_DOWN) && trim_right_engine_DOWN_status) {
        CanPlayer(trim_right_engine_DOWN_off_dump);
        if (trim_right_engine_DOWN_status) {
            trim_right_engine_DOWN_status = !trim_right_engine_DOWN_status;
        }
        std::cout << printStatusGyroController(trim_right_engine_DOWN) << std::endl;
    }

    // trim_general_UP
    if (gpioRead(trim_general_UP) && !trim_general_UP_status) {
        CanPlayer(trim_general_UP_on_dump);
        if (!trim_general_UP_status) {
            trim_general_UP_status = !trim_general_UP_status;
        }
        std::cout << printStatusGyroController(trim_general_UP) << std::endl;
    }
    if (!gpioRead(trim_general_UP) && trim_general_UP_status) {
        CanPlayer(trim_general_UP_off_dump);
        if (trim_general_UP_status) {
            trim_general_UP_status = !trim_general_UP_status;
        }
        std::cout << printStatusGyroController(trim_general_UP) << std::endl;
    }

    // trim_general_DOWN
    if (gpioRead(trim_general_DOWN) && !trim_general_DOWN_status) {
        CanPlayer(trim_general_DOWN_on_dump);
        if (!trim_general_DOWN_status) {
            trim_general_DOWN_status = !trim_general_DOWN_status;
        }
        std::cout << printStatusGyroController(trim_general_DOWN) << std::endl;
    }
    if (!gpioRead(trim_general_DOWN) && trim_general_DOWN_status) {
        CanPlayer(trim_general_DOWN_off_dump);
        if (trim_general_DOWN_status) {
            trim_general_DOWN_status = !trim_general_DOWN_status;
        }
        std::cout << printStatusGyroController(trim_general_DOWN) << std::endl;
    }

    // starlink_On_Off
    if (gpioRead(starlink_On_Off) && !starlink_On_Off_status) {
        CanPlayer(starlink_On_Off_on_dump);
        if (!starlink_On_Off_status) {
            starlink_On_Off_status = !starlink_On_Off_status;
        }
        std::cout << printStatusGyroController(starlink_On_Off) << std::endl;
    }
    if (!gpioRead(starlink_On_Off) && starlink_On_Off_status) {
        CanPlayer(starlink_On_Off_off_dump);
        if (starlink_On_Off_status) {
            starlink_On_Off_status = !starlink_On_Off_status;
        }
        std::cout << printStatusGyroController(starlink_On_Off) << std::endl;
    }

    // kamet_On_Off
    if (gpioRead(kamet_On_Off) && !kamet_On_Off_status) {
        CanPlayer(kamet_On_Off_on_dump);
        if (!kamet_On_Off_status) {
            kamet_On_Off_status = !kamet_On_Off_status;
        }
        std::cout << printStatusGyroController(kamet_On_Off) << std::endl;
    }
    if (!gpioRead(kamet_On_Off) && kamet_On_Off_status) {
        CanPlayer(kamet_On_Off_off_dump);
        if (kamet_On_Off_status) {
            kamet_On_Off_status = !kamet_On_Off_status;
        }
        std::cout << printStatusGyroController(kamet_On_Off) << std::endl;
    }
}