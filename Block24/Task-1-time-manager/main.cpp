#include <iostream>
#include <ctime>
#include <map>
#include <string>


int main() {

    std::string request;
    std::string task;
    std::map<std::string, double> list;
    std::time_t time = std::time(nullptr);
    std::time_t current = std::time(nullptr);
    bool hasActive = false;

    while (true) {
        std::cout << "Enter request: " << std::endl;
        std::getline(std::cin, request);
        if (request == "exit") break;
        if (request == "begin") {
            if (hasActive) {
                time = std::time(nullptr);
                double hours = std::difftime(time, current) / 3600;
                list.insert(std::make_pair(task, hours));
            }
            std::cout << "Enter your task:" << std::endl;
            std::getline(std::cin, task);
            current = std::time(nullptr);
            hasActive = true;

        }
        if (request == "end") {
            if (hasActive) {
                time = std::time(nullptr);
                double hours = std::difftime(time, current) / 3600;
                list.insert(std::make_pair(task, hours));
                hasActive = false;
            }
        }
        if (request == "status") {

            if (hasActive) {
                std::cout << "Current task: " << task << std::endl;
            }

            if (!list.empty()) {
                std::cout << "------\nCompleted tasks: \n" << std::endl;
                for (auto i = list.begin(); i != list.end(); ++i) {
                    std::cout.precision(1);
                    std::cout << "Task: " << i->first << "\nTime spent: " << i->second << " hours.\n" << std::endl;
                }
                std::cout << "\n------" << std::endl;
            }

        }
    }


}
