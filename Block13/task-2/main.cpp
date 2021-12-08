#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<float> prices = {2.5, 4.25, 3.0, 10.0};
    vector<int> toBuy = {1, 1, 0, 3};

    float sum = 0.f;

    for (int i = 0; i < toBuy.size(); ++i) {

        if (toBuy[i] < prices.size()) {
            sum += prices[toBuy[i]];
        }

    }

    cout << "Total sum: " << sum << endl;

}
