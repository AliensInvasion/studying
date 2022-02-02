#include <iostream>
#include <vector>

using namespace std;

vector<int> erase(vector<int> vec, int num){

    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] == num) vec.erase(vec.begin() + i);
    }
    return vec;
}

int main() {

    int size;
    int num;
    vector<int> vec;

    cout << "Enter the size of vector: " << endl;
    cin >> size;

    cout << "Enter the elements: " << endl;
    for (int i = 0; i < size; ++i) {
        cin >> num;
        cin.clear();
        vec.push_back(num);
    }

    cout << "Enter the element to erase: " << endl;
    cin >> num;

    vec = erase(vec, num);

    for (int i : vec) {
        cout << i << " ";
    }

    cout << endl;

}
