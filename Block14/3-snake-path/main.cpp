#include <iostream>

using namespace std;

int main() {

    int number[5][5];
    int count = 0;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            number[i][j] = count;
            ++count;
        }
        ++i;
        for (int j = 4; i < 5 && j >= 0; --j) {
            number[i][j] = count;
            ++count;
        }
    }


    for (auto & i : number) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

}
