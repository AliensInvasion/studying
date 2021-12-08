#include <iostream>
#include <vector>

using namespace std;

vector<int> addMore(vector<int> vec, int num) {

    for (int i = 0; i < 19; ++i) {
        vec[i] = vec[i+1];
    }

    vec[19] = num;
    return vec;

}

int main() {

    vector<int> vec(20);
    int num;
    int realSize = 0;

    while (true) {

        cout << "Enter the number: " << endl;
        cin >> num;
        if (num == -1) break;

        if (realSize < vec.size()) {
            ++realSize;
            vec[realSize-1] = num;
        } else {

            vec = addMore(vec, num);
            //vec.erase(vec.begin());
            //vec.push_back(num);

        }

    }

    for (int i = 0; i < realSize; ++i) {
        cout << vec[i] << " ";
    } cout << endl;

}
