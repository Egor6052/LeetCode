#include <SFML/Network.hpp>
#include <iostream>
#include <string>
#include <SFML/Window.hpp>

int main(){
    sf::TcpSocket socket;
    sf::IpAddress ip = sf::IpAddress::getLocalAddress();

    char type;
    std::cout << "Enter type connection: [c] - client, [s] - server \n";
    std::cin >> type;

    if (type == 's'){
        sf::TcpListener listener;
        listener.listen(2000);

        if (listener.accept(socket) != sf::Socket::Done){
            std::cout << "Error!\n";
        }
    }
    else if (type == 'c'){
        if (socket.connect(ip, 2000) != sf::Socket::Done){
            std::cout << "Error!\n";
        }
    }

    std::string name;
    std::cout << "Enter your name:\n";
    std::cin >> name;

    socket.setBlocking(false); // Неблокуючий режим
    std::string message = "";
    sf::Packet packet; // Використовуємо sf::Packet

    while (true){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            std::cin >> message;
        }
        if (message != ""){
            packet.clear();
            packet << name << message; // Використовуємо sf::Packet для передачі даних
            socket.send(packet);
            message = "";
        }
        if (socket.receive(packet) == sf::Socket::Done) {
            std::string nameRec;
            std::string messageRec;

            packet >> nameRec >> messageRec; // Отримуємо дані з sf::Packet
            std::cout << nameRec << ": " << messageRec << "\n";
        }
    }

    return 0;
}
