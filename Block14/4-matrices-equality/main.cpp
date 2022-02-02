#include <iostream>

using namespace std;

int main() {

    int A[4][4];
    int B[4][4];
    bool equal = true;

    std::cout << "Enter matrix A:" << std::endl;

    for (auto & i : A) {
        for (int & j : i) {
            cin >> j;
            cin.clear();
        }
    }

    std::cout << "Enter matrix B:" << std::endl;

    for (auto & i : B) {
        for (int & j : i) {
            cin >> j;
            cin.clear();
        }
    }

    for (int i = 0; i < 4 && equal; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (A[i][j] != B[i][j]) {
                equal = false;
                break;
            }
        }
    }

    if (equal) cout << "Matrices are equal." << endl;
    else cout << "Matrices are not equal." << endl;
}
