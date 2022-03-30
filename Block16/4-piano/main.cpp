#include <iostream>

enum tone
{
    C = 1,
    D = 2,
    E = 4,
    F = 8,
    G = 16,
    A = 32,
    B = 64
};

void makeOutput(std::string str) {
    for (char i : str) {
        if (i == ' ') {
            std::cout << std::endl;
        } else {
            int toneMask = 1 << ((int) i - 49);
            if (toneMask & C) std::cout << "DO ";
            if (toneMask & D) std::cout << "RE ";
            if (toneMask & E) std::cout << "MI ";
            if (toneMask & F) std::cout << "FA ";
            if (toneMask & G) std::cout << "SOL ";
            if (toneMask & A) std::cout << "LA ";
            if (toneMask & B) std::cout << "SI ";
        }

    }
}

bool check(std::string str){
    bool good = true;
    for (char i : str) {
        if (i < '1' || i > '7') good = false;
    }
    if (good) return true;
    else return false;
}

int main() {

    std::string chain;

    for (int i = 0; i < 12; ++i) {
        std::cout << "Enter the block of tones #" << i+1 << ":" << std::endl;
        std::string block;
        std::cin >> block;
        while(!check(block)) {
            std::cout << "Wrong input! Enter Again:" << std::endl;
            std::cin >> block;
        }
        chain += block + " ";
    }

    makeOutput(chain);

}
