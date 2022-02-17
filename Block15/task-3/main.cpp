#include <iostream>
#include <vector>

using namespace std;


int main() {

    int num;
    int realSize = 0;
    bool next = true;
    bool full = false;

    vector<int> vec(5);

    while (true) {

        cout << "\nEnter the element:" << endl;
        cin >> num;
        cin.clear();

        if (num == -2) break;

        else if (num == -1) {
            if (realSize > 0) cout << "fifth element = " << vec[0] << endl;
            else cout << "Error. No elements in array." << endl;
        }

        else if (realSize < 5) {
            vec[realSize++] = num;
        }

        else if (num < vec[0]) vec[0] = num;

        else next = false;

        while (next && num != -1) {
            next = false;
            bool breakFlag = false;
            for (int i = 0; i+1 < realSize; ++i) {
                if (vec[i] < vec[i+1]) {
                    if (!full) next = true;
                    breakFlag = true;
                    swap(vec[i], vec[i+1]);
                } else if (breakFlag) break;
            }
        }
        if (realSize == 5) full = true;
        next = true;
    }
}
