#include <iostream>

void reverse(int *arr){
    for (int i = 0; i < 5; ++i) {
        std::swap(*(arr+i), *(arr+9-i));
    }
}

int main() {

    int arr[10] = {0,1,2,3,4,5,6,7,8,9};

    reverse(arr);

    for (int i = 0; i < 10; ++i) {
        std::cout << *(arr + i);
    }

}
