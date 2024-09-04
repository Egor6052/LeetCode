#include <iostream>
#include <string>

#include "../lib/Computer.h"

Computer::Computer(){
	namePC = "NoName";
	addresLocalNetwork = "-";
	IP = "-";
	MAC = "-";
	technologyLocalNetworc = "-";
	NetworkAdress = "-";
	NetworkMask = "-";
	gatewayAdress = "-";
	interface = "-";
	metrics = "-";
}

Computer::~Computer(){ }
