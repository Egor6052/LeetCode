#include <iostream>
#include <curl/curl.h>
#include "../lib/SmsBomber.h"

SmsBomber::SmsBomber(){
	this->toNumber = "";
	this->from = "";
	this->body = "";
}
SmsBomber::~SmsBomber(){

}

void SmsBomber::setTo(std::string valueNumber){
	this->toNumber = valueNumber;
}

void SmsBomber::setFrom(std::string valueFrom){
	this->from = valueFrom;
}

void SmsBomber::setBody(std::string valueBody){
	this->body = valueBody;
}

std::string SmsBomber::getTo(){
	return toNumber;
}
std::string SmsBomber::getFrom(){
	return from;
}
std::string SmsBomber::getBody(){
	return body;
}


const std::string ACCOUNT_SID = "Your SID";
const std::string AUTH_TOKEN = "Your TOKEN";

void SmsBomber::sendSMS(const std::string& toNumber, const std::string& from, const std::string& body) {
    CURL* curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        std::string url = "https://api.twilio.com/2010-04-01/Accounts/" + ACCOUNT_SID + "/Messages.json";
        std::string auth = ACCOUNT_SID + ":" + AUTH_TOKEN;

        // Використовуємо результат curl_easy_escape() як std::string
        std::string data = "To=" + std::string(curl_easy_escape(curl, toNumber.c_str(), toNumber.length())) +
                           "&From=" + std::string(curl_easy_escape(curl, from.c_str(), from.length())) +
                           "&Body=" + std::string(curl_easy_escape(curl, body.c_str(), body.length()));

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_USERNAME, ACCOUNT_SID.c_str());
        curl_easy_setopt(curl, CURLOPT_PASSWORD, AUTH_TOKEN.c_str());
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());

        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;

        curl_easy_cleanup(curl);
    }
}

