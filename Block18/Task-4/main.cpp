#include <iostream>


void evenDigits(long long &n, int &ans){

    if (n%2 == 0) {
        ++ans;
    }
    n /= 10;
    if (n > 0) evenDigits(n,ans);

}

int main() {

    long long n;
    int ans = 0;
    std::cout << "Enter the long long number:" << std::endl;
    std::cin >> n;
    evenDigits(n,ans);
    std::cout << ans;

}
