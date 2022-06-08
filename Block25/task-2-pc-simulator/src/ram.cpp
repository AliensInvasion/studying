#include "ram.h"

int num[8] = {0, 0, 0, 0, 0, 0, 0, 0};

void write(int (&numbers)[8]) {
    for (int i = 0; i < 8; ++i) {
        num[i] = numbers[i];
    }
};

int *read() {
    return num;
};