#pragma once
#ifndef API_H
#define API_H

#include <iostream>
#include <string.h>

class API {
    private:
        std::string api;
        std::string pathJSON;

    public:
        API();
        ~API();

        // std::string getCurrentDateTime();
        void stream();

        void sendToRaspberry();

};

#endif