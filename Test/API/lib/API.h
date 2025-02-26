#pragma once
#ifndef API_H
#define API_H

#include <iostream>
#include <string.h>

class API {
    private:
        std::string ip;
        std::string apiGetJson;
        std::string pathJSON;

    public:
        API();
        ~API();

        // std::string getCurrentDateTime();
        void stream();

        void setJsonPath(std::string valuePathJSON);

        std::string getJSON();
        void sendToRaspberry();
        void logData();
        
        std::string getCurrentDateTime();

};

#endif