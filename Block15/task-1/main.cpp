#include <iostream>
#include <vector>

using namespace std;


int main() {

    int step = 1;
    int sum = 0;
    int temp = 0;
    int I = 0;
    int J = 0;
    vector<int> vec = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    while (step < vec.size()) {

        cout << "------" << endl;
        int i = 0;

        for (int j = step; j < vec.size(); ++j, ++i) {

            for (int k = i; k <= j; ++k) {
                sum += vec[k];
            }

            cout << "Range: " << j-i << " (" << i << "-" << j << ") Sum = " << sum << endl;

            if (sum > temp) {
                temp = sum;
                I = i;
                J = j;
            }
            sum = 0;
        }
        ++step;
    }
    cout << "\nMax sum = " << temp << endl;
    cout << "i = " << I << " j = " << J << endl;
}