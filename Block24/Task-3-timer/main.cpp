#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>

std::time_t get(){

    std::string request;
    std::cout << "Enter minutes and seconds (MM/SS):" << std::endl;
    std::getline(std::cin, request);

    std::tm temp{};
    std::stringstream stream;
    stream << request;
    stream >> std::get_time(&temp, "%M/%S");
    if (stream.fail()) return -1;

    std::time_t target = std::time(nullptr);
    std::tm targetInfo = *std::localtime(&target);
    targetInfo.tm_min += temp.tm_min;
    targetInfo.tm_sec += temp.tm_sec;
    target = std::mktime(&targetInfo);
    return target;
}

int main() {

    std::time_t target;

    do target = get();
    while (target == -1);

    std::time_t now = std::time(nullptr);

    int currentSecond = 0;

    while (now != target) {
        now = std::time(nullptr);
        std::time_t temp = target - now;
        std::tm tempInfo = *std::localtime(&temp);
        if (currentSecond != tempInfo.tm_sec) {
            std::cout << "Time left: " << tempInfo.tm_min;
            std::cout << " minutes,  " << tempInfo.tm_sec;
            std::cout << " seconds." << std::endl;
        }
        currentSecond = tempInfo.tm_sec;
    }

    std::cout << "DING! DING! DING!" << std::endl;
    return 0;
}
