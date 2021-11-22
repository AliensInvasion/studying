#include <iostream>

int main() {

    std::cout << "Enter the names: " << std::endl;

    std::string names[10];

    for (int i = 0; i < 10; ++i) {
        std::cin >> names[i];
    }

    //std::string names[] = {"name1", "name2", "name3", "name4", "name5", "name6", "name7", "name8", "name9", "name0"};
    int number = 0;

    for (int i = 0; i < 3; ++i) {
        std::cout << "Enter the number of apartment: " << std::endl;
        std::cin >> number;
        if (number < 1 || number > 10) {
            std::cout << "No apartment with such number." << std::endl;
        } else std::cout << names[number-1] << std::endl;
        std::cin.clear();
    }

}
