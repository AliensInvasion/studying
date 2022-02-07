#include <iostream>
#include <vector>

using namespace std;


int main() {

    int num;
    bool next = true;

    vector<int> vec;

    while (true) {

        cout << "Enter the element:" << endl;
        cin >> num;
        cin.clear();

        if (num == -2) break;
        else if (num == -1) {
            if (vec.size() >= 5){
                cout << "fifth element = " << vec[vec.size()-5] << endl;
            }
        }
        else vec.push_back(num);

        while (next) {
            next = false;
            for (int i = 0; i + 1 < vec.size(); ++i) {
                if (vec[i] < vec[i+1]) {
                    swap(vec[i], vec[i+1]);
                    next = true;
                }
            }

        }

        next = true;

        cout << endl;

        for (int i = vec.size()-1; i >= 0; --i) {
            cout << vec[i] << " ";
        }

        cout << endl;

    }

}
