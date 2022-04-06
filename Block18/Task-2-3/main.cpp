#include <iostream>

int hops(int distance, int maxHop = 3) {

    if (distance < 0) {
        return 0;
    }
    if (distance == 0) {
        return 1;
    }

    int count = 0;

    for (int i = 1; i <= maxHop; ++i) {
        count += hops((distance - i), maxHop);
    }

    return count;
}


int main() {

    int distance, maxHop;
    std::cout << "Enter the distance:" << std::endl;
    std::cin >> distance;
    std::cout << "Enter the max hop value:" << std::endl;
    std::cin >> maxHop;

    std::cout << hops(distance, maxHop);

}
