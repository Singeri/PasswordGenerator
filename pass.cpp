#include <iostream>
#include <string>
#include <random>
#include <algorithm>

int main() {

    std::string length_characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string length_numbers = "0123456789";
    std::string length_symbols = "!@#$%^_";

    std::cout << "Enter password length: ";
    int len;
    std::cin >> len;

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> type_dist(0, 2);

    std::string password = "";

    for (int i = 0; i < len; i++) {
        int type = type_dist(gen);
        char c;

        if (type == 0) {
            std::uniform_int_distribution<> letter_dist(0, length_characters.size() - 1);
            c = length_characters[letter_dist(gen)];
        } else if (type == 1) {
            std::uniform_int_distribution<> number_dist(0, length_numbers.size() - 1);
            c = length_numbers[number_dist(gen)];
        } else {
            std::uniform_int_distribution<> symbol_dist(0, length_symbols.size() - 1);
            c = length_symbols[symbol_dist(gen)];
        }

        password += c;
    }

    std::cout << "Generated password: " << password << "\n";
}