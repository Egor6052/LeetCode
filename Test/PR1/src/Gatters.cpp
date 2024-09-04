#include <iostream>
#include <string>
#include "../lib/Computer.h"

std::string Computer::getNamePC(){
	return this->namePC;
}
std::string Computer::getAddresLocalNetwork(){
	return this->addresLocalNetwork;
}
std::string Computer::getIP(){
	return this->IP;
}
std::string Computer::getMAC(){
	return this->MAC;
}
std::string Computer::getTechnologyLocalNetwork(){
	return this->technologyLocalNetworc;
}
std::string Computer::getNetworkAdress(){
	return this->NetworkAdress;
}
std::string Computer::getNetworkMask(){
	return this->NetworkMask;
}
std::string Computer::getGatewayAdress(){
	return this->gatewayAdress;
}
std::string Computer::getInterface(){
	return this->interface;
}
std::string Computer::getMetrics(){
	return this->metrics;
}