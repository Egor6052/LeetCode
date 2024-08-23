#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

std::string numbers = "1234567890";
std::string alphabet = "abcdefghijklmnopkqrstuvwxyz";
std::string up_alphabet = alphabet;
std::transform(up_alphabet.begin(), up_alphabet.end(), up_alphabet.begin(), ::toupper);
std::string mix_alph = alphabet + up_alphabet;
std::string digits = "*_-&₽#@%=/";

std::vector<char> password;

bool flag = true;

bool num = false;
bool up_alph_flag = false;
bool low_alph = false;
bool all_alph = false;
bool digi = false;

void alphabet_choice(const std::string& user_sug) {
    if (user_sug.find("мален") != std::string::npos) {
        low_alph = true;
    }
    if (user_sug.find("больш") != std::string::npos) {
        up_alph_flag = true;
    }
    if (user_sug.find("раз") != std::string::npos) {
        all_alph = true;
    }
}

int main() {
    std::srand(std::time(0)); // Ініціалізація генератора випадкових чисел

    while (flag) {
        std::string user_sug;
        std::getline(std::cin, user_sug);

        int n = 0;
        bool isNumeric = false;

        for (const auto& word : user_sug) {
            if (isdigit(word)) {
                isNumeric = true;
                n = std::stoi(user_sug);
                break;
            }
        }
        if (!isNumeric) {
            n = std::rand() % 12 + 10; // Генеруємо випадкове число між 10 і 21
        }

        if (user_sug.find("цифр") != std::string::npos) {
            num = true;
        }
        if (user_sug.find("букв") != std::string::npos) {
            alphabet_choice(user_sug);
        }
        if (user_sug.find("знак") != std::string::npos) {
            digi = true;
        }
        if (user_sug.find("стоп") != std::string::npos) {
            flag = false;
        }

        while (n > 0) {
            if (num) {
                password.push_back(numbers[std::rand() % numbers.length()]);
                n--;
            }
            if (up_alph_flag) {
                password.push_back(up_alphabet[std::rand() % up_alphabet.length()]);
                n--;
            }
            if (low_alph) {
                password.push_back(alphabet[std::rand() % alphabet.length()]);
                n--;
            }
            if (all_alph) {
                password.push_back(mix_alph[std::rand() % mix_alph.length()]);
                n--;
            }
            if (digi) {
                password.push_back(digits[std::rand() % digits.length()]);
                n--;
            }
        }

        std::random_shuffle(password.begin(), password.end());
        std::string final_password(password.begin(), password.end());
        std::cout << final_password << std::endl;
    }

    return 0;
}
