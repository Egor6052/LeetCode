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

        void stream();

        void setJsonPath(std::string valuePathJSON);
        std::string getJSON();
        
        void sendToRaspberry();
        void logData();
        
        char getChar();
        std::string getCurrentDateTime();

};

#endif