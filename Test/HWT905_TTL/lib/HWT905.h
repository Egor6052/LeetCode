#pragma once
#ifndef HWT905_H
#define HWT905_H

#include <iostream>
#include <string.h>

class HWT905 {
    private:
        std::string name;
        std::string serialPort;
        std::string data;
        std::string time;

    public:
        HWT905();
        ~HWT905();

        std::string getCurrentDateTime();
        void stream();

};

#endif