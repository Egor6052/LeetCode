// #include <iostream>
// #include <fstream>
// #include <filesystem>
// #include <curl/curl.h>
// #include <nlohmann/json.hpp>
// #include "../../lib/Daemon.h"

// // Функція для запису відповіді у рядок
// size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
//     size_t totalSize = size * nmemb;
//     output->append((char*)contents, totalSize);
//     return totalSize;
// }

// std::string Daemon::getJSON() {
//     std::string response;
//     CURL* curl;
//     CURLcode res;

//     curl_global_init(CURL_GLOBAL_DEFAULT);
//     curl = curl_easy_init();

//     if (curl) {
//         curl_easy_setopt(curl, CURLOPT_URL, apiGetJson.c_str());
//         curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
//         curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
//         res = curl_easy_perform(curl);

//         if (res != CURLE_OK) {
//             std::cerr << "Curl error: " << curl_easy_strerror(res) << std::endl;
//             curl_easy_cleanup(curl);
//             curl_global_cleanup();
//             return "Error: API request failed!";
//         }

//         curl_easy_cleanup(curl);
//     }

//     curl_global_cleanup();

//     if (response.empty()) {
//         return "Error: empty response from server!";
//     }

//     // Парсинг JSON
//     try {
//         nlohmann::json jsonData = nlohmann::json::parse(response);
//         return jsonData.dump(4);
//     } catch (const nlohmann::json::parse_error& e) {
//         std::cerr << "JSON parsing error:" << e.what() << std::endl;
//         return "Error: JSON could not be parsed!";
//     }
// }