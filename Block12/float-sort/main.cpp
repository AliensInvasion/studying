#include <iostream>
#include <limits>

int main() {

    float max = std::numeric_limits<float>::max();

    float temp;
    int cycles = 0;

    float numbers[15]; // = {11.4, 11.1, 10.6, 10.7, 1.08, 1.05, 11.5, 10.8, 1.10, 1.09, 11.2, 11.3, 1.16, 1.17, 11.8};

    std::cout << "Enter the float numbers:" << std::endl;

    for (int i = 0; i < 15; ++i) {
        std::cin >> numbers[i];
        while (numbers[i] == -max || numbers[i] == max) {
            std::cin.clear();
            std::cout << "Wrong number! Enter again:" << std::endl;
            std::cin >> numbers[i];
        }
    }

    bool inOrder = true;

    for (int i = 0;; ++i) {

        if (i == 15) {
            i = 0;
            cycles++;
            std::cout << "Full cycles: " << cycles << std::endl;
            if (inOrder) break;
            else inOrder = true;
        }

        if (i + 1 < 15 && numbers[i+1] < numbers[i]) {
            inOrder = false;
            if (cycles > 0) {
                temp = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = temp;
            }
        }

        std::cout << i << ": " << numbers[i] << std::endl;

    }

    std::cout << "\n---\n" << "Row in order:" << std::endl;

    for (int i = 0; i < 15 ; ++i) {
        std::cout << i << ": " << numbers[i] << std::endl;
    }

}
