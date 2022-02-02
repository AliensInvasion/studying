#include <iostream>

using namespace std;

int pop(bool matrix[][12], int coords[][2]){

    int count = 0;

    for (int i = coords[0][0]; i <= coords[1][0]; ++i) {
        for (int j = coords[0][1]; j <= coords[1][1]; ++j) {

            if (matrix[i][j]) {
                count++;
                cout << count << " pop!" << endl;
                matrix[i][j] = false;
            }

        }
    }
    return count;
}

void init(bool matrix[][12]){

    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            matrix[i][j] = true;
        }
    }

}

void show(bool matrix[][12]) {

    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            matrix[i][j] ? cout << "O" : cout << "x";
        } cout << endl;
    }

}

void checkCoords(int  matrix[][2]){

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            while (matrix[i][j] < 0 || matrix[i][j] > 11){
                cin.ignore(1000, '\n');
                cout << "Error. Number " << matrix[i][j] << " is < 0 or > 11. Enter the correct value:" << endl;
                cin >> matrix[i][j];
                cin.clear();
            }
        }
    }
}

void getCoords(int matrix[][2]) {

    cout << "Enter coords of the points(X1 Y1 X2 Y2):" << endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin >> matrix[i][j];
            cin.clear();
        }
    }
    checkCoords(matrix);
    if (matrix[0][0] > matrix[1][0]) swap(matrix[0][0],matrix[1][0]);
    if (matrix[0][1] > matrix[1][1]) swap(matrix[0][1],matrix[1][1]);
}



int main() {

    int coords[2][2];
    int bubbles = 144;
    bool bubbleWrap[12][12];

    init(bubbleWrap);
    show(bubbleWrap);

    while (bubbles > 0) {
    getCoords(coords);
    bubbles -= pop(bubbleWrap, coords);
    show(bubbleWrap);
    cout << "Bubbles left:" << bubbles << endl;
    }

    cout << "That's all Folks!" << endl;

}
