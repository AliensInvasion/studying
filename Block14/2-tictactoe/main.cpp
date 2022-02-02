#include <iostream>

using namespace std;

void add(char matrix[][3], char c) {

    int x, y;
    cout << c << " turn. Enter coords:" << endl;
    cin >> x >> y;
    cin.clear();
    while (x > 2 || x < 0 || y > 2 || y < 0 || matrix[x][y] != ' ') {
        cout << "Wrong coords. Enter again:" << endl;
        cin >> x >> y;
        cin.clear();
    }
    matrix[x][y] = c;

}

char check(char matrix[][3]) {

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {

            //cout << "i = " << i << ", j = " << j << ", char = [" << matrix[i][j] << "]" << endl;

            char current = matrix[i][j];

            if (current == ' ') break;

            if (j == 0 && current == matrix[i][j+1] && current == matrix[i][j+2]) {
                cout << "row match" << endl;
                return current;
            }

            if (i == 0 && current == matrix[i+1][j] && current == matrix[i+2][j]) {
                cout << "col match" << endl;
                return current;
            }

            if (i == 0 && j == 0 && current == matrix[i+1][j+1] && current == matrix[i+2][j+2]) {
                cout << "diag match" << endl;
                return current;
            }

            if (i == 2 && j == 0 && current == matrix[i-1][j+1] && current == matrix[i-2][j+2]) {
                cout << "reverse diag match" << endl;
                return current;
            }

        }
    }
    return ' ';
}

void show(char matrix[][3]) {

    cout << "------" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "------" << endl;

}

void init(char matrix[][3]){
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matrix[i][j] = ' ';
        }
    }
}

int main() {

    char matrix[3][3];
    init(matrix);
    char winner = ' ';

    for (int i = 1; winner == ' '; ++i) {

        if (i % 2 != 0) {
            add(matrix, 'X');
        } else {
            add(matrix, 'O');
        }

        show(matrix);
        winner = check(matrix);

        if (winner == ' ' && i == 9) winner = '?';

    }

    if (winner == '?') {
        cout << "\nNo winner." << endl;
    } else cout << "\n" << winner << " wins!" << endl;

}
