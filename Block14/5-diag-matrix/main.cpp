#include <iostream>

using namespace std;

int main() {

    int M[4][4];

    std::cout << "Enter matrix M:" << std::endl;

    for (auto & i : M) {
        for (int & j : i) {
            cin >> j;
            cin.clear();
        }
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (i != j) {M[i][j] = 0;}
        }
    }

    for (auto & i : M) {
        for (int j : i) {
            cout << j;
        }
        cout << endl;
    }

}