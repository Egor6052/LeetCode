#pragma once
#ifndef SMSBOMBER_H
#define SMSBOMBER_H
#include <iostream>
#include <string>

class SmsBomber{
	private:
		std::string toNumber;
	    std::string from;
	    std::string body;
	public:
		SmsBomber();
		~SmsBomber();

		void setTo(std::string valueNumber);
		void setFrom(std::string valueFrom);
		void setBody(std::string valueBody);

		std::string getTo();
		std::string getFrom();
		std::string getBody();

		void sendSMS(const std::string& toNumber, const std::string& from, const std::string& body);

};


#endif