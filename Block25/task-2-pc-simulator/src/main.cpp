#include <iostream>
#include "cpu.h"
#include "disk.h"
#include "gpu.h"
#include "kbd.h"

int main() {
    std::string request;
    do {
        std::cout << "Enter your request:" << std::endl;
        std::cin >> request;
        if (request == "sum"){
           std::cout << "Sum of the numbers is: ";
           std::cout << compute() << std::endl;
        }
        if (request == "save"){
            save();
        }
        if (request == "load"){
            if (load()) {
               std::cout << "Data loaded from disk." << std::endl;
            } else {
               std::cout << "Error! Nothing loaded." << std::endl;
            }
        }
        if (request == "input"){
            get();
            std::cout << "Success!" << std::endl;
        }
        if (request == "display"){
            show();
        }
    } while (request != "exit");
}
