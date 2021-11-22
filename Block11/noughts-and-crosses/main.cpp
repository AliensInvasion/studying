#include <iostream>

char getElement(int x, int y, std::string str) {

    int col;
    int row = 0;

    for (int i = 0; i < str.length(); i++) {

        if (i > 2) {
            col = i % 3;
        } else col = i;

        if (i > 2 && i % 3 == 0) row++;

        if (col == x && row == y) return str[i];

    }

    return '?';

}

int gameCheck(const std::string str) {

    bool winX = false;
    bool winO = false;
    std::string row;
    std::string col;
    std::string diag1;
    std::string diag2;
    std::string checkString;


    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            checkString += getElement(j, i, str);
            row += getElement(j, i, str);
            col += getElement(i, j, str);

            if (i == j) {
                diag1 += getElement(i, j, str);
                diag2 += getElement(i, 2 - j, str);
            }

        }

        if (row[0] == row[1] && row [0] == row[2] && row[0] != '.') {
            if (winX || winO) return 3;
            if (row[0] == 'X') winX = true;
            if (row[0] == 'O') winO = true;
        }

        if (col[0] == col[1] && col [0] == col[2] && col[0] != '.') {
            if (winX || winO) return 3;
            if (col[0] == 'X') winX = true;
            if (col[0] == 'O') winO = true;
        }

        if (diag1[0] == diag1[1] && diag1 [0] == diag1[2] && diag1[0] != '.') {
            if (winX || winO) return 3;
            if (diag1[0] == 'X') winX = true;
            if (diag1[0] == 'O') winO = true;
        }

        if (diag2[0] == diag2[1] && diag2 [0] == diag2[2] && diag2[0] != '.') {
            if (winX || winO) return 3;
            if (diag2[0] == 'X') winX = true;
            if (diag2[0] == 'O') winO = true;
        }

        row.clear();
        col.clear();

    }

    int xSum = 0;
    int oSum = 0;

    for (int i = 0; i < 9; i++) {
        if (checkString[i] == 'X') xSum++;
        if (checkString[i] == 'O') oSum++;
    }

    //std::cout << "X: " << xSum << " O: " << oSum << std::endl;

    if (xSum  > oSum + 1 || oSum > xSum) return 3;

    if (!winX && !winO) {
        return 0;
    }

    if (winX) {
        if (xSum == oSum) return 3;
        else return 1;
    }

    if (winO) {
        if (xSum > oSum) return 3;
        else return 2;
    }

    return 0;


}

bool symbolsCorrect(std::string str) {

    std::string allowed = "XO.";
    bool found;

    if (str.length() != 3) return false;

    for (int i = 0; i < 4; i++) {

        found = false;

        for (int j = 0; j < 4; j++) {
            if (str[i] == allowed[j]) found = true;
        }

        if (!found) return false;

    }

    return true;

}

int main() {

    int answer;
    bool error = false;

    std::cout << "Enter 3 strings ('X', 'O', '.'):" << std::endl;
    std::string top, middle, bottom;
    std::cin >> top >> middle >> bottom;

    if (!symbolsCorrect(top) || !symbolsCorrect(middle) || !symbolsCorrect(bottom)) error = true;

    std::string str = top + middle + bottom;

    if (!error) {
        answer = gameCheck(str);
    } else answer = 3;

    if (answer == 0) std::cout << "Nobody" << std::endl;
    if (answer == 1) std::cout << "X won" << std::endl;
    if (answer == 2) std::cout << "O won" << std::endl;
    if (answer == 3) std::cout << "Incorrect" << std::endl;

}