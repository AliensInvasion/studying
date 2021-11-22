#include <iostream>
#include <limits>

std::string encrypt_caesar(std::string str, int number) {

    if (abs(number) > 25) number %= 25;

    for (int i = 0; i < str.length(); i++) {

        if (str[i] >= 'a' && str[i] <= 'z') {

            if ((str[i] + number) < 'a') {

                str[i] = ('z' + 1) - ('a' - (str[i] + number));

            } else if ((str[i] + number) > 'z') {

                str[i] = ('a' - 1) + ((str[i] + number) - 'z');

            } else str[i] = str[i] + number;

        }

        if (str[i] >= 'A' && str[i] <= 'Z') {

            if ((str[i] + number) < 'A') {

                str[i] = ('Z' + 1) - ('A' - (str[i] + number));

            } else if ((str[i] + number) > 'Z') {

                str[i] = ('A' - 1) + ((str[i] + number) - 'Z');

            } else str[i] = str[i] + number;

        }

    }

    return str;

}

std::string decrypt_caesar(std::string str, int number) {

    return encrypt_caesar(str, -number);

}

int main() {

    int max = std::numeric_limits<int>::max();
    int min = std::numeric_limits<int>::min();
    int number;
    std::string str;

    std::cout << "Enter the string:" << std::endl;
    std::getline(std::cin, str);
    std::cout << "Enter the number:" << std::endl;
    std::cin >> number;

    while (number == min || number == max) {

        std::cin.clear();
        std::cout << "Number is not correct. Enter again:" << std::endl;
        std::cin >> number;

    }

    std::cout << "Original: " << std::endl;
    std::cout << str << std::endl;

    std::string encrypted = encrypt_caesar(str, number);
    std::string decrypted = decrypt_caesar(encrypted, number);

    std::cout << "Encrypted: " << std::endl;
    std::cout << encrypted << std::endl;

    std::cout << "Decrypted: " << std::endl;
    std::cout << decrypted << std::endl;

    if (decrypted == str) {

        return 0;

    } else return 1;

}
