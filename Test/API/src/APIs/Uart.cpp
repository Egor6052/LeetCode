#include <iostream>
#include <fstream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include "../../lib/API.h"

void API::sendToRaspberry() {
    const std::string url = "http://192.168.10.212:5000/send";

    // Завантажуємо JSON з файлу
    std::ifstream file(pathJSON);
    if (!file.is_open()) {
        std::cerr << "Помилка відкриття файлу: " << pathJSON << std::endl;
        return;
    }

    nlohmann::json jsonData;
    file >> jsonData;
    file.close();

    // Ініціалізація curl
    CURL* curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Помилка ініціалізації CURL!" << std::endl;
        return;
    }

    std::string jsonString = jsonData.dump();

    struct curl_slist* headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonString.c_str());

    CURLcode res = curl_easy_perform(curl);

    if (res != CURLE_OK) {
        std::cerr << "Помилка CURL: " << curl_easy_strerror(res) << std::endl;
    } else {
        std::cout << "JSON відправлено успішно!" << std::endl;
    }

    curl_easy_cleanup(curl);
    curl_slist_free_all(headers);
}


