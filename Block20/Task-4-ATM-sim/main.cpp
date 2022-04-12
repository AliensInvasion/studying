#include <iostream>
#include <fstream>
#include <ctime>

void fillEmpty() {
    std::ifstream atmRead("..\\resources\\atm.bin", std::ios::binary);
    char first = 0;
    if (atmRead.is_open()) {
        atmRead >> first;
        atmRead.close();
    }
    if (first < 97 || first > 103) {
        std::ofstream atmWrite("..\\resources\\atm.bin", std::ios::binary);
        for (int i = 0; i < 1000; ++i) {
            char random = std::rand() % 6 + 97;
            atmWrite << random;
        }
        atmWrite.close();
    }
}

bool get(int &sum, char *bank){

    int value[6] = {5000, 2000, 1000, 500, 200, 100};

    if (sum % 100 != 0) return false;

    int i = 0;
    int temp = sum;

    while (sum > 0) {

        temp -= value[i];

        if (temp >= 0) {

            for (int j = 0; ; ++j) {

                if (j == 1000) {
                    ++i;
                    if (i == 6) {
                        std::cout << "Error! Not enough money in ATM." << std::endl;
                        return false;
                    }
                    j = 0;
                }
                if (bank[j] == 97 + i) {
                    std::cout << "Price: " << value[i] << std::endl;
                    std::cout << "Found in " << j << std::endl;
                    bank[j] = 103;
                    sum -= value[i];
                    temp = sum;
                    break;
                }
            }

            std::cout << sum << " more left." << std::endl << std::endl;

        } else {
            temp = sum;
            ++i;
        }
    }


    if (sum == 0) {
        std::ofstream atmWrite("..\\resources\\atm.bin", std::ios::binary);
        atmWrite.write(bank, 1000);
        atmWrite.close();
        return true;
    }

    else return false;

}

bool fill(){

    std::ifstream atmRead("..\\resources\\atm.bin", std::ios::binary);
    if (!atmRead.is_open()) return false;
    char bank[1000];
    atmRead.read(bank, 1000);
    atmRead.close();

    for (char &i : bank) {
        if (i < 97 || i > 103) return false;
    }

    for (char &i : bank) {
        if (i == 103) i = std::rand() % 6 + 97;
    }

    std::ofstream atmWrite("..\\resources\\atm.bin", std::ios::binary);
    for (char &i : bank) {
        atmWrite << i;
    }
    atmWrite.close();

    return true;

}

int main() {

    std::srand(std::time(nullptr));
    fillEmpty();

    std::string type;
    std::cout << "Select the type of operation (+ / -):" << std::endl;
    std::cin >> type;

    while (type != "-" && type != "+") {
        std::cin.clear();
        std::cout << "Select the type of operation (+ / -):" << std::endl;
        std::cin >> type;
    }

    if (type == "+") {
        if (fill()) return 0;
        else return 1;
    }

    if (type == "-") {

        std::ifstream atmRead("..\\resources\\atm.bin", std::ios::binary);
        if (!atmRead.is_open()) return 1;
        char bank[1000];
        atmRead.read(bank,  1000);
        atmRead.close();

        int sum;
        std::cout << "Enter the amount to receive:" << std::endl;
        std::cin >> sum;

        if (get(sum, bank)) return 0;
        else return 1;

    }

}
