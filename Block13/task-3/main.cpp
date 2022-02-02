#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> vec(20);
    int num = 0;
    int curPos = 0;
    bool vecFull = false;

    cout << "Enter the values:" << endl;
    while (true) {
        cin >> num;
        cin.clear();
        if (num == -1) break;
        if (curPos == vec.size()) {
            curPos = 0;
            vecFull = true;
        }
        vec[curPos++] = num;
    }

    for (int i = curPos; vecFull && i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }

    for (int i = 0; i < curPos; ++i) {
        cout << vec[i] << " ";
    }

}
