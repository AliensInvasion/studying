#include <iostream>

using namespace std;

int main() {

    int spoon[12][2];
    int fork[12][2];
    int knife[12][2];
    int dessertSpoon[12][2];
    int plate[12][2];
    int chair[12][2];


    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 2; ++j) {

            spoon[i][j] = 1;
            fork[i][j] = 1;
            knife[i][j] = 1;
            dessertSpoon[i][j] = 0;
            plate[i][j] = 2;
            chair[i][j] = 1;

            if (i == 0) {
                ++dessertSpoon[i][j];
                ++plate[i][j];
            }
        }
    }

    ++chair[4][0]; //give a chair to 5, 1
    --spoon[2][1]; //spoon stolen from 3, 2
    --spoon[0][0]; //1, 1 give a spoon to 3,2
    ++spoon[2][1]; //1, 1 give a spoon to 3,2
    --plate[0][0]; //excess plate taken from 1, 1

    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 2; ++j) {

            cout << "PLACE = " << "\t" << "(" << i+1 << ", " << j+1 << ")\n"
                 << "SPOONS = " << "\t" << spoon[i][j] << "\n"
                 << "FORKS = " << "\t" << fork[i][j] << "\n"
                 << "KNIFES = " << "\t" << knife[i][j] << "\n"
                 << "DES. SPOONS = " << "\t" << dessertSpoon[i][j] << "\n"
                 << "PLATES = " << "\t" << plate[i][j] << "\n"
                 << "CHAIRS = " << "\t" << chair[i][j] << "\n" << endl;

        }
    }
}
