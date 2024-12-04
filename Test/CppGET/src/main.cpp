#include <websocketpp/config/asio_no_tls_client.hpp>
#include <websocketpp/client.hpp>


#include <iostream>
#include <string>

typedef websocketpp::client<websocketpp::config::asio_client> client;

class WebSocketClient {
public:
    WebSocketClient() {
        // Ініціалізація WebSocket++ клієнта
        ws_client.init_asio();
        ws_client.set_open_handler([this](websocketpp::connection_hdl hdl) {
            this->on_open(hdl);
        });
        ws_client.set_message_handler([this](websocketpp::connection_hdl hdl, client::message_ptr msg) {
            this->on_message(hdl, msg);
        });
        ws_client.set_fail_handler([](websocketpp::connection_hdl hdl) {
            std::cerr << "З'єднання не вдалося." << std::endl;
        });
        ws_client.set_close_handler([](websocketpp::connection_hdl hdl) {
            std::cout << "З'єднання закрито." << std::endl;
        });
    }

    void connect(const std::string& uri) {
        websocketpp::lib::error_code ec;
        client::connection_ptr con = ws_client.get_connection(uri, ec);

        if (ec) {
            std::cerr << "Помилка створення з'єднання: " << ec.message() << std::endl;
            return;
        }

        ws_client.connect(con);
        ws_client.run();
    }

private:
    void on_open(websocketpp::connection_hdl hdl) {
        std::cout << "З'єднання встановлено. Надсилаю дані..." << std::endl;

        // Надсилайте ваші дані тут:
        ws_client.send(hdl, "Ваші дані тут", websocketpp::frame::opcode::text);
    }

    void on_message(websocketpp::connection_hdl hdl, client::message_ptr msg) {
        std::cout << "Отримано повідомлення: " << msg->get_payload() << std::endl;
    }

    client ws_client;
};

int main() {
    WebSocketClient client;

    // Задайте URL вашого WebSocket-сервера
    std::string server_url = "wss://example.com/socket";

    client.connect(server_url);

    return 0;
}
