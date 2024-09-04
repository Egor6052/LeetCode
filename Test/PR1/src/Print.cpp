#include <iostream>
#include <string>
#include "../lib/Computer.h"


void Computer::Print(){
	std::cout << "Name PC: " << Computer::getNamePC() << "\n"
	<< "Addres Local Network: " << Computer::getAddresLocalNetwork() << "\n"
	<< "IP: " << Computer::getIP() << "\n"
	<< "MAC: " << Computer::getMAC() << "\n"
	<< "Technology Local Network: " << Computer::getTechnologyLocalNetwork() << "\n"
	<< "Network Adress: " << Computer::getNetworkAdress() << "\n"
	<< "Network Mask: " << Computer::getNetworkMask() << "\n"
	<< "Gateway Adress: " << Computer::getGatewayAdress() << "\n"
	<< "Interface: " << Computer::getInterface() << "\n"
	<< "Metrics: " << Computer::getMetrics() << std::endl;


	std::cout << "Ping: " << Computer::ping("google.com", "odessa.net", "op.edu.ua") << "\n"
			<< "Traceroute: " << Computer::traceroute("google.com", "odessa.net", "op.edu.ua") << "\n"
			<< "Nslookup: " << Computer::nslookup("google.com", "odessa.net", "op.edu.ua") << std::endl;
}