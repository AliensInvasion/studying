#include <iostream>
#include <map>


bool check(std::string &str1, std::string &str2) {

    std::map<char, int> first, second;

    for (char &i : str1) {
        auto it = first.find(i);
        if (it == first.end()) {
            first.insert(std::make_pair(i, 1));
        }
        else {
            it->second++;
        }
    }

    for (char &i : str2) {
        auto it = second.find(i);
        if (it == second.end()) {
            second.insert(std::make_pair(i, 1));
        }
        else {
            it->second++;
        }
    }

    auto it1 = first.begin();
    auto it2 = second.begin();

    while (it1 != first.end() && it2 != second.end()) {
        if (it1->first != it2->first || it1->second != it2->second) {
            return false;
        }
        it1++;
        it2++;
    }

    if (it1 == first.end() && it2 == second.end()) return true;
    else return false;

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
