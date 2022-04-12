#include <iostream>
#include <fstream>

int main() {

    int sum = 0;
    std::string target;
    std::cout << "Enter the name of the fish:" << std::endl;
    std::cin >> target;

    std::ifstream river("..\\resources\\river.txt");
    std::ofstream basket("..\\resources\\basket.txt", std::ios::app);
    if (!river.is_open() || !basket.is_open()) return 1;

    while (!river.eof()) {
        std::string temp;
        river >> temp;
        if (temp == target) {
            basket << target << std::endl;
            ++sum;
        }
    }

    std::cout << sum << " fish caught." << std::endl;

    river.close();
    basket.close();

}
