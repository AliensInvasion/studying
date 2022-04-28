#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include <iomanip>
#include <map>
#include <vector>

int main() {

    std::map<std::time_t, std::vector<std::string>> list;
    std::string request;
    std::time_t rawTime;

    while (request != "end") {
        std::string name, date;
        std::cout << "Enter person name and birth date(YYYY/MM/DD):" << std::endl;
        std::getline(std::cin, request);
        if (request == "end") break;

        std::stringstream stream(request);
        stream >> name >> date;
        std::stringstream dateStream(date);
        std::tm birthday{};
        dateStream >> std::get_time(&birthday, "%Y/%m/%d");

        if (dateStream.fail()) {
            std::cout << "Error!" << std::endl;
            continue;
        }
        rawTime = std::mktime(&birthday);
        if (rawTime == -1) {
            std::cout << "Error! Date is invalid." << std::endl;
            continue;
        }

        if (list[rawTime].empty()) {
            std::vector<std::string> vec;
            list.insert(std::make_pair(rawTime, vec));
            list[rawTime].push_back(name);
        }
        else {
            list[rawTime].push_back(name);
        }

    }

    std::vector<std::vector<std::string>> winners;
    std::map<std::time_t, std::vector<std::vector<std::string>>> candidates;
    std::time_t now = std::time(nullptr);
    std::tm nowInfo = *std::localtime(&now);

    for (auto it : list) {
        std::tm currentInfo = *std::localtime(&(it.first));

        if ((currentInfo.tm_mon == nowInfo.tm_mon) && (currentInfo.tm_mday == nowInfo.tm_mday)) {
                winners.push_back(it.second);
        }
        else if (currentInfo.tm_mon == nowInfo.tm_mon) {
            if (currentInfo.tm_mday > nowInfo.tm_mday) {
                currentInfo.tm_year = nowInfo.tm_year;
            }
            if (currentInfo.tm_mday < nowInfo.tm_mday) {
                currentInfo.tm_year = nowInfo.tm_year + 1;
            }
        }
        else if (currentInfo.tm_mon < nowInfo.tm_mon) {
            currentInfo.tm_year = nowInfo.tm_year + 1;
        }
        else if (currentInfo.tm_mon > nowInfo.tm_mon) {
            currentInfo.tm_year = nowInfo.tm_year;
        }

        std::time_t temp = std::mktime(&currentInfo);
        if (candidates[temp].empty()) {
            std::vector<std::vector<std::string>> vec;
            candidates.insert(std::make_pair(temp, vec));
            candidates[temp].push_back(it.second);
        } else {
            candidates[temp].push_back(it.second);
        }

    }

    if (candidates.empty()) return 0;

    if (!winners.empty()) {
        std::cout << "Today is birthday of:" << std::endl;
        for (auto &i : winners) {
            for (auto &j : i) {
                std::cout << j << " " << std::put_time(&nowInfo, "(%m/%d)") << std::endl;
            }
        }
        return 0;
    }

    std::cout << "Next birthday is:" << std::endl;
    auto it = candidates.begin();
    std::tm currentInfo = *std::localtime(&(it->first));
    for (auto &i : it->second) {
        for (auto &j : i) {
            std::cout << j << " " << std::put_time(&currentInfo, "(%m/%d)") << std::endl;
        }
    }

}