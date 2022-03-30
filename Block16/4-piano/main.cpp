#include <iostream>
#include <sstream>

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
    for (int i = 0; i < str.length()-1; ++i) {
        if (str[i] == ' ') {
            std::cout << std::endl;
        } else {
            int toneNumber = str[i] - 48;
            tone T = (tone) (1 << (toneNumber - 1));
            if (T == C) std::cout << "DO ";
            if (T == D) std::cout << "RE ";
            if (T == E) std::cout << "MI ";
            if (T == F) std::cout << "FA ";
            if (T == G) std::cout << "SOL ";
            if (T == A) std::cout << "LA ";
            if (T == B) std::cout << "SI ";
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

    std::stringstream chain;

    for (int i = 0; i < 12; ++i) {
        std::cout << "Enter the block of tones #" << i+1 << ":" << std::endl;
        std::string block;
        std::cin >> block;
        while(!check(block)) {
            std::cout << "Wrong input! Enter Again:" << std::endl;
            std::cin >> block;
        }
        chain << block << " ";
    }

    std::string result;
    result = chain.str();
    makeOutput(result);

}
