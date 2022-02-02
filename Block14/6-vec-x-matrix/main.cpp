#include <iostream>

using namespace std;

void showVector(float V[]){

    for (int i = 0; i < 4; ++i) {
        cout << V[i] << endl;
    }

}

void showMatrix(float M[][4]) {

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << M[i][j] << "\t";
        } cout << endl;
    }

}

int main() {
    
    float result[4];
    
    cout << "Enter 4x4 matrix M:" << endl;
    float matrix[4][4];

    for (auto & i : matrix) {
        for (float & j : i) {
            cin >> j;
            cin.clear();
        }
    }

    showMatrix(matrix);
    
    cout << "\n" << "Enter 4-vector V:" << endl;
    float vec[4];

    for (float & i : vec) {
        cin >> i;
        cin.clear();
    }

    showVector(vec);

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            result[i] += vec[j] * matrix[i][j];
        }
    }

    cout << "\n" <<"Multiplication result:" << endl;

    showVector(result);

}
