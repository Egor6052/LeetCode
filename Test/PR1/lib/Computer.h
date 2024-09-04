#pragma once
#ifndef COMPUTER_H
#define COMPUTER_H

#include <iostream>
#include <string>

class Computer {
private:
	std::string namePC;
	std::string addresLocalNetwork;
	std::string IP;
	std::string MAC;
	std::string technologyLocalNetworc;
	std::string NetworkAdress;
	std::string NetworkMask;
	std::string gatewayAdress;
	std::string interface;
	std::string metrics;
	
public:
	Computer();
	~Computer();

	void setNamePC();
	void setAddresLocalNetwork();
	void setIP();
	void setMAC();
	void setTechnologyLocalNetwork();
	void setNetworkAdress();
	void setNetworkMask();
	void setGatewayAdress();
	void setInterface();
	void setMetrics();
	
	std::string getNamePC();
	std::string getAddresLocalNetwork();
	std::string getIP();
	std::string getMAC();
	std::string getTechnologyLocalNetwork();
	std::string getNetworkAdress();
	std::string getNetworkMask();
	std::string getGatewayAdress();
	std::string getInterface();
	std::string getMetrics();

	void ping(std::string valueAddress1, std::string valueAddress2, std::string valueAddress3);
	void traceroute(std::string valueAddress1, std::string valueAddress2, std::string valueAddress3);
	void nslookup(std::string valueAddress1, std::string valueAddress2, std::string valueAddress3);

	void Print();
};

#endif