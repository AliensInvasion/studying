#include <iostream>
#include <string>
#include <map>

bool check(std::string &str) {
    if (str[0] >= 'a' && str[0] <= 'z') str[0] -= 32;
    for (int i = 1; i < str.length(); ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;
        if (str[i] < 'a' || str[i] > 'z') return false;
    }
    return true;
}


int main() {
    std::map<std::string, int> registry;
    while (true) {
        std::string request;
        std::cout << "Call next or add new name:" << std::endl;
        std::cin >> request;
        while (!check(request)) {
            std::cout << "Call next or add new name:" << std::endl;
            std::cin >> request;
        }
        if (request == "Exit") break;
        if (request == "Next") {
            auto it = registry.begin();
            if (it == registry.end()) continue;
            std::cout << "Next: " << it->first << std::endl;
            if (it->second > 0) it->second--;
            if (it->second == 0) registry.erase(it);
            continue;
        }
        bool hasName = false;
        for (auto &it : registry) {
            if (it.first == request)  {
                hasName = true;
                it.second++;
            }
        }
        if (!hasName) registry.insert(std::make_pair(request,0));
    }
}
