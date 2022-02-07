#include <iostream>
#include <vector>

using namespace std;

int main() {

    int left, right;

    vector<int> vec =  {-100,-50, -5, 1, 10, 15};
    //vector<int> vec =  {-100,-50, -5, -4, -2, -1};
    //vector<int> vec =  {-137, -77, -40, -21, -11, -7, -2, -1, 0, 1, 2, 3, 6, 7, 11};

    if (!vec.empty()) {

        if (vec.front() >= 0 && vec.back() >= 0) {

            for (int i : vec) {
                cout << i << " ";
            } cout << endl;

        } else if (vec.front() < 0 && vec.back() < 0) {

            for (int i = vec.size()-1; i >= 0; --i) {
                cout << vec[i] << " ";
            } cout << endl;

        } else {

            for (int i = 0; i < vec.size()-1; ++i) {
                if (vec[i] < 0 && vec[i+1] >= 0) {
                    left = i;
                    right = i+1;
                }
            }

            bool proceed = true;
            while (proceed) {
                if (left < 0) {
                        while (right < vec.size()) {
                            cout << vec[right] << " ";
                            ++right;
                        }
                }
                else if (right >= vec.size()) {
                        while (left >= 0) {
                            cout << vec[left] << " ";
                            --left;
                        }
                }
                else if (abs(vec[left]) > abs(vec[right])) {
                        cout << vec[right] << " ";
                        ++right;
                }
                else if (abs(vec[left]) <= abs(vec[right])) {
                        cout << vec[left] << " ";
                        --left;
                }

                if (left < 0 && right >= vec.size()) proceed = false;
            }
        }
    }
}