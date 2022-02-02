#include <iostream>

using namespace std;

int main() {

    int number[5][5];
    int count = 0;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {

            int temp;
            if (i % 2 == 0) temp = j;
            else temp = (4 - j);

            number[i][temp] = count;
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
