#include <iostream>
#include <fstream>
#include <ctime>

int main() {

    std::srand(std::time(nullptr));

    int height, width;
    std::cout << "Enter height:" << std::endl;
    std::cin >> height;
    std::cout << "Enter width:" << std::endl;
    std::cin >> width;

    std::ofstream stream("..\\resources\\pic.txt");
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (std::rand() % 2 == 0){
                stream << '*';
            }
            else stream << 'X';
        }
        stream << std::endl;
    }
}
