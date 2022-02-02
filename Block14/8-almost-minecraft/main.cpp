#include <iostream>

using namespace std;

void show(int matrix[][5]) {
    cout << "-----" << endl;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << matrix[i][j];
        } cout << endl;
    }
    cout << "-----" << endl;
}

void slice(int matrix[][5]) {

    int height;

    cin.ignore(1000, '\n');
    cout << "Enter the height of slice:" << endl;
    cin >> height;
    cin.clear();

    while (height < 0 || height > 9) {
        cout << "Entered height is < 0 or > 9. Enter again:" << endl;
        cin >> height;
        cin.clear();
    }

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            matrix[i][j] >= height ? matrix[i][j] = 1 : matrix[i][j] = 0;
        }
    }

    cout << "Slice of your world on height " << height << ":" << endl;
    show(matrix);

}

void check(int matrix[][5]) {

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            while (matrix[i][j] < 0 || matrix[i][j] > 9){
                cin.ignore(1000, '\n');
                cout << "Error. Number " << matrix[i][j] << " is < 0 or > 9. Enter the correct value:" << endl;
                cin >> matrix[i][j];
                cin.clear();
            }
        }
    }
}

void init(int matrix[][5]) {

    cout << "Enter the heights of the points:" << endl;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> matrix[i][j];
            cin.clear();
        }
    }
    check(matrix);
    cout << "Your world:" << endl;
    show(matrix);
}

int main() {

    int world[5][5];

    init(world);
    slice(world);

}
