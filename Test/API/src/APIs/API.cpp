#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <nlohmann/json.hpp>
#include "../../lib/API.h"

#define BUFFER_SIZE 4096

API::API() {
    this->ip = "192.168.100.1";
    this->pathJSON = "";
    this->apiGetJson = "http://192.168.100.1:3000/signalk/v1/api/sources";
}

API::~API() {}

void API::stream() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        std::cerr << "Помилка створення сокету!" << std::endl;
        return;
    }

    struct sockaddr_in server{};
    server.sin_family = AF_INET;
    server.sin_port = htons(3000);
    inet_pton(AF_INET, ip.c_str(), &server.sin_addr);

    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        std::cerr << "Помилка підключення до сервера!" << std::endl;
        close(sock);
        return;
    }

    std::string request = "GET /signalk/v1/api/vessels/self HTTP/1.1\r\n"
                        "Host: 192.168.10.212\r\n"
                        "Connection: close\r\n\r\n";
    send(sock, request.c_str(), request.length(), 0);

    char buffer[BUFFER_SIZE];
    std::string response;
    ssize_t bytesReceived;
    while ((bytesReceived = recv(sock, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[bytesReceived] = '\0';
        response += buffer;
    }

    close(sock);

    // Витягуємо JSON з HTTP-відповіді
    std::size_t jsonStart = response.find("\r\n\r\n");
    if (jsonStart != std::string::npos) {
        std::string jsonData = response.substr(jsonStart + 4);

        try {
            // Парсимо JSON
            nlohmann::json jsonObject = nlohmann::json::parse(jsonData);

            // Записуємо у файл у форматі з відступами
            std::ofstream outFile("../response.json");
            if (outFile.is_open()) {
                outFile << jsonObject.dump(4); // Форматування з відступами у 4 пробіли
                outFile.close();
                std::cout << "JSON збережено у файл response.json" << std::endl;
            } else {
                std::cerr << "Помилка відкриття файлу!" << std::endl;
            }
        } catch (nlohmann::json::parse_error& e) {
            std::cerr << "Помилка парсингу JSON: " << e.what() << std::endl;
        }
    } else {
        std::cerr << "Помилка: JSON не знайдено!" << std::endl;
    }
}
