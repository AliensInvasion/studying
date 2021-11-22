#include <iostream>

int main() {

    int temp;
    int answer;
    int cycles = 0;

    int numbers[15] = {114, 111, 106, 107, 108, 105, 115, 108, 110, 109, 112, 113, 116, 117, 118};
    //int numbers[15] = {6546, 6435, 4324, 4222, 2152, 953, 1232, 956, 546, 432, 212, 65, 113, 65, 33};

    bool found = false;
    bool inOrder = true;

    for (int i = 0; !found; ++i) {

        if (i == 15) {
            i = 0;
            cycles++;
            std::cout << "Full cycles: " << cycles << std::endl;
            if (inOrder) return 0;
            else inOrder = true;
        }

        if (i + 1 < 15 && numbers[i+1] == numbers[i]) {
            answer = numbers[i];
            found = true;
        }

        if (i + 1 < 15 && numbers[i+1] < numbers[i]) {
            if (cycles > 0) {
                temp = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = temp;
            }
            inOrder = false;
        }

        std::cout << i << ": " << numbers[i] << std::endl;

    }

    std::cout << "Repeating number: " << answer << std::endl;

}
