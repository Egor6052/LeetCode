#include <iostream>
#include <fstream>
#include <filesystem>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include "../../lib/API.h"

// Функція для запису відповіді у рядок
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}

std::string API::getJSON() {
    std::string response;
    CURL* curl = curl_easy_init();
    
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://192.168.100.1:3000/signalk/v1/api/sources");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        
        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "cURL error: " << curl_easy_strerror(res) << std::endl;
        }
        
        curl_easy_cleanup(curl);
    } else {
        std::cerr << "Failed to initialize cURL" << std::endl;
    }

    if (response.empty()) {
        return "Помилка: порожня відповідь від сервера!";
    }

    return response;
}
