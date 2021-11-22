#include <iostream>

bool part_check(std::string str){

    int first = 0;
    int second = 0;
    int third = 0;


    for (int i = 0; i < str.length(); i++){

        if (!(str[i] >= '0' && str[i] <= '9')) {
            std::cout << "symbols 0-9 check failed" << std::endl;
            return false;
        }

    }

    if (str.length() > 1 && str[0] == '0') {
        std::cout << "symbols after '0' check failed" << std::endl;
        return false;
    }

    if (str.length() == 1) {
        first = str[0] - '0';
    } else if (str.length() == 2) {
        first = (str[0] - '0') * 10;
        second = str[1] - '0';
    } else if (str.length() == 3) {
        first = (str[0] - '0') * 100;
        second = (str[1] - '0') * 10;
        third = str[2] - '0';
    }

    int result = first + second + third;

    if (result > 255) {
        std::cout << "part > 255 check failed" << std::endl;
        return false;
    }

    return true;

}

bool ip_check(std::string str) {

    bool error = false;
    bool partEnd = false;
    int partsSum = 0;
    int dotsCount = 0;
    std::string part;

    for (int i = 0; i < str.length() && !error; i++ ) {

        if (str[i] == '.') {
            partEnd = true;
            dotsCount++;
        } else {
            part += str[i];
        }


        if (partEnd || i + 1 == str.length()) {

            if (part.length() == 0 || part.length() > 3) {
                std::cout << "part length check failed" << std::endl;
                return false;
            }

            if (!part_check(part)) {
                error = true;
            }

            partsSum++;
            part.clear();
            partEnd = false;

        }

    }

    if (!error) {
        if (partsSum != 4) {
            std::cout << "parts sum check failed" << std::endl;
            return false;
        }
        if (dotsCount != 3) {
            std::cout << "dots count check failed" << std::endl;
            return false;
        }
    }

    if (error) return false;
    else return true;

}


int main() {

    std::cout << "Enter IP address:" << std::endl;
    std::string ip;
    std::cin >> ip;

    if (ip_check(ip)) {
        std::cout << "IP address is correct!" << std::endl;
    } else {
        std::cout << "IP address is not correct!" << std::endl;
    }
}