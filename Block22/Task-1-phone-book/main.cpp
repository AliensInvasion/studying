#include <iostream>
#include <map>
#include <vector>
#include <string>

bool checkName(std::string &str) {
    if (str[0] >= 'a' && str[0] <= 'z') str[0] -= 32;
    for (int i = 1; i < str.length(); ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;
        if (str[i] < 'a' || str[i] > 'z') return false;
    }
    return true;
}

bool checkNumber(std::string &str) {
    int i = 0;
    for (; i < str.length(); ++i) {
        if (i == 2 || i == 5) {
            if (str[i] != '-') return false;
        }
        else if (str[i] < '0' || str[i] > '9'){
            return false;
        }
    }
    if (i != 8) return false;
    return true;
}

int next(std::string &str, int &pos) {
    for (int i = pos; i < str.length(); ++i) {
        if (str[i] != ' ') return i;
    }
    return -1;
}

bool check(std::string &str, std::map<std::string, std::string> &numbersNames,
           std::map<std::string, std::vector<std::string>> &namesNumbers) {

    std::string first, second;
    int pos = 0;
    pos = next(str, pos);
    if (pos < 0) return false;

    if (str[pos] < '0' || str[pos] > '9') { //not number

        if (str[pos] >= 'a' && str[pos] <= 'z') str[pos] -= 32;
        if (str[pos] < 'A' || str[pos] > 'Z') return false; //not name
        else { //name

            for (int i = pos; i < str.length(); ++i) {
                if (str[i] == ' ') break;
                first += str[i];
                ++pos;
            }

            if (!checkName(first)) {
                std::cout << "name is not correct" << std::endl;
                return false;
            }

            for (auto &it : namesNumbers) {
                if (it.first == first) {
                    std::cout << "Name: " << it.first << std::endl;
                    std::cout << "Number: ";
                    for (auto &i : it.second) {
                       std::cout << i << " ";
                    }
                    std::cout << std::endl;
                }
            }

        }
    }

    else { //number

        for (int i = pos; i < str.length(); ++i) {
            if (str[i] == ' ') break;
            first += str[i];
            ++pos;
        }
        if (!checkNumber(first)) {
            std::cout << "number is not correct" << std::endl;
            return false;
        }

        pos = next(str, pos);
        if (pos > 0) { //number, name

            for (int i = pos; i < str.length(); ++i) {
                if (str[i] == ' ') break;
                second += str[i];
            }
            if (!checkName(second)) {
                std::cout << "name is not correct" << std::endl;
                return false;
            }

            for (auto it= numbersNames.begin(); it != numbersNames.end(); ++it) {
                if (it->first == first) {
                    std::cout << "Number already exists." << std::endl;
                    return false;
                }
            }

            for (auto it = namesNumbers.begin(); ; ++it) {
                if (it == namesNumbers.end()) {
                    std::vector<std::string> vec;
                    vec.push_back(first);
                    namesNumbers.insert(std::make_pair(second, vec));
                    break;
                }
                if (it->first == second){
                    bool exist = false;
                    for (auto & i : it->second) {
                        if (i == first) {
                            exist = true;
                        }
                    }
                    if (!exist) {
                        it->second.push_back(first);
                    }
                }
            }

            numbersNames.insert(std::make_pair(first,second));
        }
        else { //number
            std::map<std::string, std::string>::iterator it;
            for (it = numbersNames.begin(); it != numbersNames.end(); ++it) {
                if (it->first == first) {
                    std::cout << "Number: " << it->first << std::endl;
                    std::cout << "Name: " << it->second << std::endl;
                }
            }
        }
    }
    return true;
}

int main() {

    std::map<std::string, std::string> numbersNames;
    std::map<std::string, std::vector<std::string>> namesNumbers;

    while (true) {
        std::string request;
        std::cout << "Phone-base. Enter your request:" << std::endl;
        std::getline(std::cin, request);
        if (request == "exit") break;
        bool good = check(request, numbersNames, namesNumbers);
        while (!good) {
            std::cout << "Error!" << std::endl;
            std::cout << "Phone-base. Enter your request:" << std::endl;
            std::getline(std::cin, request);
            good = check(request, numbersNames, namesNumbers);
        }
    }
}
