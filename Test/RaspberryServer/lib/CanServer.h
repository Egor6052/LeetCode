#pragma once

#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
#include <pistache/endpoint.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <sys/socket.h>
#include <net/if.h>
#include <unistd.h>
#include <cstring>

class CanServer {
    public:
        explicit CanServer(Address addr) : httpEndpoint(std::make_shared<Http::Endpoint>(addr)) {}

        void init(size_t threads = 1);
        
        void start();

    private:

        std::shared_ptr<Http::Endpoint> httpEndpoint;
        Rest::Router router;

        void setupRoutes() {
            Rest::Routes::Post(router, "/send", Rest::Routes::bind(&CanServer::sendCan, this));
        }

        void sendCan(const Rest::Request& request, Http::ResponseWriter response) {
            try {
                auto jsonData = nlohmann::json::parse(request.body());

                if (!jsonData.contains("sentence")) {
                    response.send(Http::Code::Bad_Request, "Помилка: відсутнє поле 'sentence'");
                    return;
                }

                std::string message = jsonData["sentence"];
                if (sendCanMessage(message)) {
                    response.send(Http::Code::Ok, "CAN-повідомлення надіслано");
                } else {
                    response.send(Http::Code::Internal_Server_Error, "Помилка при відправці CAN");
                }
            } catch (const std::exception& e) {
                response.send(Http::Code::Internal_Server_Error, std::string("Помилка JSON: ") + e.what());
            }
        }
};

#endif