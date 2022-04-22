#include <iostream>
#include <map>


bool check(std::string &str1, std::string &str2) {

    std::map<char, int> anagram;

    for (char &i : str1) {
        anagram[i]++;
    }

    for (char &i : str2) {
        anagram[i]--;
        if(anagram[i] < 0)
            return false;
        if(anagram[i] == 0)
            anagram.erase(i);
    }

    return  anagram.empty();
}

int main() {
    std::string first, second;
    std::cout << "Enter first:" << std::endl;
    std::cin >> first;
    std::cout << "Enter second:" << std::endl;
    std::cin >> second;

    if(check(first, second)) std::cout << "Is anagram." << std::endl;
    else std::cout << "Not anagram." << std::endl;
    return 0;
}
