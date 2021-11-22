#include <iostream>

bool isZero(std::string str) {

    bool found;
    std::string symbols = "-.0";

    for (int i = 0; i < str.length(); i++) {

        found = false;

        for (int j = 0; j < symbols.length(); j++) {

            if (str[i] == symbols[j]) found = true;

        }

        if (!found) return false;

    }

    return true;

}

std::string intPart (std::string str) {

    bool nextCheck = false;

    std::string part;

    if (str[0] == '.') return part;

    if (str[0] == '0') nextCheck = true;

    if (str[0] == '-' && str[1] == '0') {
        part += str[0];
        nextCheck = true;
    }


    for (int i = 0; i < str.length(); i++) {

        if (nextCheck) {

            if (i + 1 < str.length() && str[i + 1] != '0') {

                nextCheck = false;
                if (str[i + 1] == '.') return part;

            }

        } else {

            if (i + 1 < str.length()) {

                if (str[i + 1] == '.') {
                    part += str[i];
                    return part;
                } else part += str[i];

            }

            if (i + 1 == str.length()) part += str[i];

        }

    }

    return part;

}

std::string fracPart (std::string str) {

    bool get = false;

    std::string part;

    for (int i = 0; i < str.length(); i++) {

        if (get) part += str[i];

        if (i + 1 < str.length() && str[i] == '.') {

            i++;
            part += str[i];
            get = true;

        }

    }

    return part;

}


int comparison(std::string first, std::string second) {

    bool inverse = false;

    int firstIntLength = (int) intPart(first).length();
    int secondIntLength = (int) intPart(second).length();
    int firstFracLength = (int) fracPart(first).length();
    int secondFracLength = (int) fracPart(second).length();

    int count = 0;

    if (isZero(first) && isZero(second)) return 0;

    if (first[0] == '-' && second[0] == '-') {
        inverse = true;
        count++;
    } else if (first[0] == '-') return 2; else if (second[0] == '-') return 1;


    if (firstIntLength > secondIntLength) {
        if (inverse) return 2; else return 1;
    } else if (firstIntLength < secondIntLength) {
        if (inverse) return 1; else return 2;
    } else {

        for (; count < firstIntLength; count++) {

            if (intPart(first)[count] > intPart(second)[count]) {
                if (inverse) return 2; else return 1;
            }

            if (intPart(first)[count] < intPart(second)[count]) {
                if (inverse) return 1; else return 2;
            }

        }

        std::string fracFirst = fracPart(first);
        std::string fracSecond = fracPart(second);

        if (firstFracLength > secondFracLength) {
            for (int i = 0; i < (firstFracLength - secondFracLength); i++) fracSecond += '0';
        }
        if (firstFracLength < secondFracLength) {
            for (int i = 0; i < (secondFracLength - firstFracLength); i++) fracFirst += '0';
        }

        for (count = 0; count <= fracFirst.length(); count++) {

            if (fracFirst[count] > fracSecond[count]) {
                if (inverse) return 2; else return 1;
            }

            if (fracFirst[count] < fracSecond[count]) {
                if (inverse) return 1; else return 2;
            }

        }

        return 0;

    }

}


bool isCorrect(std::string str) {

    bool hasDot = false;
    bool hasNumber = false;
    bool error = false;

    for (int i = 0; i < str.length() && !error; i++) {

        if (str[i] == '-') {
            if (i > 0) error = true;
        } else if (str[i] == '.') {
            if (hasDot) error = true;
            else hasDot = true;
        } else if (str[i] >= '0' && str[i] <= '9') {
            hasNumber = true;
        } else {
            error = true;
        }

    }

    if (error || !hasNumber) return false;
    else return true;

}

int main() {

    int result;
    bool error = false;
    std::string first, second;
    std::cout << "Enter the numbers:" << std::endl;
    std::cin >> first >> second;

    if (!isCorrect(first) || !isCorrect(second)) error = true;

    if (!error) {
        result = comparison(first, second);
    } else {
        std::cout << "error" << std::endl;
        return 0;
    }

    if (result == 0) std::cout << "equal" << std::endl;
    if (result == 1) std::cout << "first" << std::endl;
    if (result == 2) std::cout << "second" << std::endl;

}