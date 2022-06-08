#include <iostream>
#include "ram.h"
#include "kbd.h"

void get() {

    int numbers[8];
    std::cout << "Enter 8 numbers:" << std::endl;
    for (int &number : numbers) {
        std::cin >> number;
    }
    write(numbers);

};