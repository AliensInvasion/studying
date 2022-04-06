#include <iostream>
#include <vector>

void swap(std::vector<int> &a, int *b) {

    for (int i = 0; i < 4; ++i) {
        std::swap(a[i], *(b+i));
    }

};

int main() {
    std::vector<int> a = {1,2,3,4};

    int b[4] = {2,4,6,8};

    swap(a,b);

    for (int i = 0; i < 4; ++i) {
        std::cout << a[i];
    }

    std::cout << std::endl;

    for (int i : b) {
        std::cout << i;
    }
}
