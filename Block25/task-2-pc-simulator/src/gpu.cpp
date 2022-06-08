#include <iostream>
#include "ram.h"
#include "gpu.h"

void show() {
    int *ram = read();
    for (int i = 0; i < 8; ++i) {
        std::cout << *(ram+i) << " ";
    }
    std::cout << std::endl;
};