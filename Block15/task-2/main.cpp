#include <iostream>
#include <vector>

using namespace std;

int main() {

    int I, J;
    vector<int> vec = {2, 7, 11, 15};
    int sum = 9;
    bool found = false;

    for (int i = 0; !found && i < vec.size()-1; ++i) {
        for (int j = i+1; !found && j < vec.size(); ++j) {
            if (vec[i]+vec[j] == sum) {
                found = true;
                I = i; J = j;
            }
        }
    }

    if (found) cout << "\n" << sum << " = " << vec[I] << " + " << vec[J] << endl;
    else cout << "\nNot found." << endl;
}
