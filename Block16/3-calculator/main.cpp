#include <iostream>

bool correct (std::string str) {

    bool haveSign = false;
    bool good = false;
    int dots = 0;

    if (str.length() < 3) return false;

    for (int i = 0; i < str.length(); ++i) {

        if (str[i] >= '0' && str[i] <= '9') good = true;

        if (str[i] == '/' || str[i] == '*' || str[i] == '+' || str[i] == '-') {
            if (!haveSign) haveSign = true;
            else return false;
            good = true;
        }

        if (str[i] == '.') {
            if (i == 0 && (str[i+1] < '0' || str[i+1] > '9')) return false;
            if (i == str.length()-1 && (str[i-1] < '0' || str[i-1] > '9')) return false;
            if (dots == 2) return false;
            else ++dots;
            good = true;
        }

        if (!good) return false;
        good = false;

    }


    if (haveSign) return true;
    else return false;
}

int main() {

    std::string firstStr;
    std::string secondStr;
    char sign;
    double first;
    double second;
    double result;

    std::cout << "Enter an expression:" << std::endl;
    std::string input;
    std::cin >> input;

    while (!correct(input)) {
        std::cout << "Input is not correct! Enter again:" << std::endl;
        std::cin >> input;
    }

    bool secondStart = false;

    for (char i : input) {
        if (i == '/' || i == '*' || i == '+' || i == '-') {
            sign = i;
            secondStart = true;
        }
        else if (!secondStart) firstStr += i;
        else secondStr += i;
    }

    first = std::stod(firstStr);
    second = std::stod(secondStr);


    if (sign == '+') result = first + second;
    if (sign == '-') result = first - second;
    if (sign == '*') result = first * second;
    if (sign == '/') result = first / second;

    std::cout << first << " " << sign << " " << second << " = " << result << std::endl;

}
