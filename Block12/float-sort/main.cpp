#include <iostream>
#include <limits>

void heapify(float arr[], int n, int i) {

    int max = i;

    int leftChild = 2*i+1;
    int rightChild = 2*i+2;

    if (leftChild < n && arr[leftChild] > arr[max]) {
        max = leftChild;
    }

    if (rightChild < n && arr[rightChild] > arr[max]) {
        max = rightChild;
    }

    if (i != max) {
        std::swap(arr[i], arr[max]);
        heapify(arr, n, max);
    }

}

void heapSort(float arr[], int n) {

    for (int i = n/2-1; i >= 0; --i) {
        heapify(arr, n, i);
    }

    for (int i = n-1; i >= 0 ; --i) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }

}

int main() {

    float max = std::numeric_limits<float>::max();
    float numbers[15]; // = {11.4, 11.1, 10.6, 10.7, 1.08, 1.05, 11.5, 10.8, 1.10, 1.09, 11.2, 11.3, 1.16, 1.17, 11.8};

    std::cout << "Enter the float numbers:" << std::endl;

    for (int i = 0; i < 15; ++i) {
        std::cin >> numbers[i];
        while (numbers[i] == -max || numbers[i] == max) {
            std::cin.clear();
            std::cout << "Wrong number! Enter again:" << std::endl;
            std::cin >> numbers[i];
        }
    }

    int n = 15;
    heapSort(numbers, n);

    std::cout << "Sorted array:" << std::endl;

    for (int i = 0; i < n; ++i) {
        std::cout << numbers[i] << " ";
    }

}
