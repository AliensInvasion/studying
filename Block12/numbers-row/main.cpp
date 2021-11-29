#include <iostream>


int main() {

    int sum = 0;
    int count = 15;
    int countSum = 0;

    int numbers[] = {114, 111, 106, 107, 108, 105, 115, 108, 110, 109, 112, 113, 116, 117, 118};

    int min = numbers[0];
    int max = numbers[0];

    for (int i = 0; i < count; ++i) {
        if (min > numbers[i]) min = numbers[i];
        if (max < numbers[i]) max = numbers[i];
        sum += numbers[i];
        countSum += i;
    }

    if (sum - (min * count) != countSum) {

        int sequenceSum = 0;
        for (int i = min; i <= max; i++) {
            sequenceSum += i;
        }

        int answer = sum - sequenceSum;
        std::cout << "Repeating number: " << answer << std::endl;

    } else std::cout << "No repeating number." << std::endl;

}
