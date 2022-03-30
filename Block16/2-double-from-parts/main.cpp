#include <iostream>

bool correct (std::string str) {

    for (char i : str) {
        if (i < '0' || i > '9') return false;
    }
    return true;
}

int main() {

    std::string firstPart;
    std::string secondPart;
    std::string partsSum;
    double result;

    std::cout <<  "Enter the first and second parts of a double: " << std::endl;
    std::cin >> firstPart;
    std::cin >> secondPart;

    while (!correct(firstPart) || !correct(secondPart)) {
        std::cout <<  "Error! Enter again: " << std::endl;
        std::cin >> firstPart;
        std::cin >> secondPart;
    }

    partsSum = firstPart + "." + secondPart;

    result = std::stod(partsSum);

    std::cout << result << std::endl;

}
