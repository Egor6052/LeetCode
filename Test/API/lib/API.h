#pragma once
#ifndef API_H
#define API_H

#include <iostream>
#include <string.h>

class API {
    private:
        std::string api;

    public:
        API();
        ~API();

        // std::string getCurrentDateTime();
        void stream();

};

#endif