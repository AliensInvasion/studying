#include <iostream>

bool first_part_check(char c) {

    std::string allowedSymbols = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!#$%&'*+-/=?^_`{|}~.";
    bool found = false;

    for (int i = 0; i < allowedSymbols.length() && !found; i++) {

        if (c == allowedSymbols[i])  {
            found = true;
        }

    }

    if (found) return true;
    else return false;

}

bool second_part_check(char c) {

    std::string allowedSymbols = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz-.";
    bool found = false;

    for (int i = 0; i < allowedSymbols.length() && !found; i++) {

        if (c == allowedSymbols[i])  {
            found = true;
        }

    }

    if (found) return true;
    else return false;

}

bool email_check(std::string str) {

    bool hasAt = false;
    bool error = false;
    int firstLength = 0;
    int secondLength = 0;
    int middle = 0;

    for (int i = 0; i < str.length() && !error; i++) {

        if (str[i] == '@') {
            if (hasAt) {
                error = true;
                std::cout << "Second '@' check failed" << std::endl;
            } else {
                middle = i;
                hasAt = true;
                i++;
            }
        }

        if (i + 1 < str.length() && str[i] == '.' && str[i + 1] == '.') {
            error = true;
            std::cout << "Double '.' check failed" << std::endl;
        }

        if (!hasAt) {

            firstLength++;

            if (!first_part_check(str[i])) {
                error = true;
                std::cout << "first_part_check failed" << std::endl;
            }

        } else {

            secondLength++;

            if (!second_part_check(str[i])) {
                error = true;
                std::cout << "second_part_check failed" << std::endl;
            }

        }

    }

    if (!error) {

        if ((middle > 0 && str[middle - 1] == '.') || (middle > 0 && middle < str.length() && str[middle + 1] == '.')) {
            error = true;
            std::cout << "'.' close to the '@' check failed" << std::endl;
        }

        if (str[0] == '.' || str[str.length() - 1] == '.') {
            error = true;
            std::cout << "First and last '.' check failed" << std::endl;
        }

        if (firstLength < 1 || firstLength > 64) {
            error = true;
            std::cout << "First part length failed " << firstLength << std::endl;
        }

        if (secondLength < 1 || secondLength > 63) {
            error = true;
            std::cout << "Second part length failed " << secondLength << std::endl;
        }

    }

    if (error) return false;
    else return true;
}


int main() {

    std::cout << "Enter e-mail:" << std::endl;
    std::string email;
    std::cin >> email;

    if (email_check(email)) {
        std::cout << "E-mail is correct!" << std::endl;
    } else {
        std::cout << "E-mail is not correct!" << std::endl;
    }
}
