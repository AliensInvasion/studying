#include <iostream>
#include <vector>

using namespace std;


int main() {

    vector<int> vec = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int answer = vec[0];
    int left = 0;
    int right = 0;
    int sum = 0;
    int negative = -1;

    for (int i = 0; i < vec.size(); ++i) {

        sum += vec[i];

        if (sum > answer) {

            answer = sum;
            left = negative + 1;
            right = i;

        }

        if (sum < 0) {
            negative = i;
            sum = 0;
        }

    }

    cout << "Left: " << left << " Right: " << right << " Sum: " << answer << endl;
    
}