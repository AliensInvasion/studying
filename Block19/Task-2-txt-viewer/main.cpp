#include <iostream>
#include <fstream>

int main() {

    std::string path;
    std::cout << "Enter the path to TXT file:" << std::endl;
    std::getline(std::cin, path);

    char buffer[10];
    std::ifstream text;

    text.open(path);

    while (!text.is_open()) {
        std::cout << "Wrong path! Enter again:" << std::endl;
        std::getline(std::cin, path);
        text.open(path);
    }

    while (!text.eof()) {

        text.read(buffer, sizeof(buffer));

        for (int i = 0; i != text.gcount(); ++i) {
            if (buffer[i] == '\n') std::cout << std::endl;
            else std::cout << buffer[i];
        }

    }

    text.close();

}
