#include "ram.h"
#include "cpu.h"


int compute() {
    int *ram = read();
    int sum = 0;
    for (int i = 0; i < 8; ++i) {
        sum += *(ram+i);
    }
    return sum;
};