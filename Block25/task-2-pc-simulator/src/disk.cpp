#include <fstream>
#include "ram.h"
#include "disk.h"

void save() {
    int *ram = read();
    std::ofstream data("data.txt");
    for (int i = 0; i < 8; ++i) {
        data << *(ram+i) << " ";
    }
    data.close();
};

bool load() {
    int numbers[8];
    std::ifstream data("data.txt");
    if (!data.is_open()) return false;
    for (int &number : numbers) {
        data >> number;
    }
    data.close();
    write(numbers);
    return true;
};
