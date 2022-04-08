#include <iostream>
#include <fstream>

int main() {

    int count = 0;

    std::cout << "Enter target word:" << std::endl;
    std::string target;
    std::cin >> target;

    std::ifstream words;
    words.open("..\\resources\\words.txt");

    while (!words.eof()) {
        std::string word;
        words >> word;
        if (word == target) {
            ++count;
        }
    }

    std::cout << count;

}
