#include <iostream>
#include <vector>

using namespace std;

vector<int> erase(vector<int> vec, int num){

    vector<int> newVec;

    for (int i = 0; i < vec.size(); ++i) {
        if (num != vec[i]) newVec.push_back(vec[i]);
    }

    return newVec;

}

int main() {

    int size;
    int num;
    vector<int> vec;

    cout << "Enter the size of vector: " << endl;
    cin >> size;

    for (int i = 0; i < size; ++i) {
        cout << "Enter the element: " << endl;
        cin >> num;
        vec.push_back(num);
    }

    cout << "Enter the element to erase: " << endl;
    cin >> num;

    vec = erase(vec, num);

    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }

    cout << endl;

}
