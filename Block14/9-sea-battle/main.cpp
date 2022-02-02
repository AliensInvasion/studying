#include <iostream>

using namespace std;

void show(char matrix[][10]) {
    cout << "  0 1 2 3 4 5 6 7 8 9" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << i << " ";
        for (int j = 0; j < 10; ++j) {
            cout << matrix[i][j] << " ";
        } cout << endl;
    }
}

int correct(int x) {

    while (x < 0 || x > 9) {
        cin.ignore(1000, '\n');
        cout << "Element " << x << " is wrong! Enter again:" << endl;
        cin >> x;
        cin.clear();
    }
    return x;

}


void closeBlocks(char matrix[][10], int x, int y, int a, int b) {

    for (int i = x-1; i <= a+1; ++i) {
        for (int j = y-1; j <= b+1; ++j) {
            if (i >= 0 && j >= 0 && i < 10 && j < 10 && matrix[i][j] == '~') {
                matrix[i][j] = '#';
            }
        }
    }
    //show(matrix);
}

void init(char matrix[][10]){
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            matrix[i][j] = '~';
        }
    }
}

int game(char first[][10], char second[][10]) {

    char radarFirst[10][10];
    char radarSecond[10][10];
    int firstHP = 20;
    int secondHP = 20;
    int x, y;
    init(radarFirst);
    init(radarSecond);

    cout << "All ships are placed and the game begins." << endl;

    while (true) {

        cout << "\n" << "First player turn." << endl;
        cout << "Your HP = " << firstHP << "." << endl;
        show(radarFirst);
        cout << "Enter the coords of target:" << endl;

        cin >> x; cin.clear();
        cin >> y; cin.clear();

        x = correct(x);
        y = correct(y);

        while (second[x][y] == '|') {
            if (radarFirst[x][y] == '~') --secondHP;
            radarFirst[x][y] = 'X';
            cout << "You hit the target! Player 2 HP = " << secondHP << "." << endl;
            show(radarFirst);
            if (secondHP == 0) break;
            cout << "Try again:" << endl;
            cin >> x; cin.clear();
            cin >> y; cin.clear();
            x = correct(x);
            y = correct(y);
        }

        if (second[x][y] == '~') {
            radarFirst[x][y] = ' ';
            cout << "You miss!" << endl;
            show(radarFirst);
        }


        if (secondHP == 0) {
            return 1;
        }

        cout << '\n' << "Second player turn." << endl;
        cout << "Your HP = " << secondHP << "." << endl;
        show(radarSecond);
        cout << "Enter the coords of target:" << endl;

        cin >> x; cin.clear();
        cin >> y; cin.clear();

        x = correct(x);
        y = correct(y);

        while (first[x][y] == '|') {
            if (radarSecond[x][y] == '~') --firstHP;
            radarSecond[x][y] = 'X';
            cout << "You hit the target! Player 1 HP = " << firstHP << "." << endl;
            show(radarSecond);
            if (firstHP == 0) break;
            cout << "Try again:" << endl;
            cin >> x; cin.clear();
            cin >> y; cin.clear();
            x = correct(x);
            y = correct(y);
        }
        if (second[x][y] == '~') {
            radarSecond[x][y] = ' ';
            cout << "You miss!" << endl;
            show(radarSecond);
        }


        if (firstHP == 0) {
            return 2;
        }

    }

}

void placeShips(char matrix[][10]) {

    int count = 4;
    int firstX, firstY, secondX, secondY;
    char closedZone[10][10];
    init(closedZone);

    while (count > 0) {
        for (int i = 0; i < count; ++i) {
            bool ok = false;
            bool error = false;

            cout << "Enter " << 5 - count << "-cell ship coords (X1 Y1";
            if (count < 4) cout << " X2 Y2):" << endl;
            else cout << "):" << endl;

            cin >> firstX; cin.clear();
            cin >> firstY; cin.clear();

            if (count < 4) {
                cin >> secondX; cin.clear();
                cin >> secondY; cin.clear();
            } else {secondX = firstX; secondY = firstY;}

            while (!ok) {

                firstX = correct(firstX);
                firstY = correct(firstY);
                if (count < 4) {
                    secondX = correct(secondX);
                    secondY = correct(secondY);
                }

                //cout << firstX << " " << firstY << " " << secondX << " " << secondY << "\n";

                if (count == 4 && closedZone[firstX][firstY] != '#') {
                    matrix[firstX][firstY] = '|';
                    ok = true;
                } else {

                    if (firstX > secondX) swap(firstX, secondX);
                    if (firstY > secondY) swap(firstY, secondY);

                    if (firstX == secondX && (secondY - firstY) == 4 - count) {
                        for (int j = firstY; j <= secondY; ++j) {
                            if (closedZone[firstX][j] == '#') error = true;
                        }
                        for (int j = firstY; !error && j <= secondY; ++j) {
                            matrix[firstX][j] = '|';
                        }
                        ok = true;
                    }

                    if (!ok && firstY == secondY && (secondX - firstX) == 4 - count) {
                        for (int j = firstX; j <= secondX; ++j) {
                            if (closedZone[j][firstY] == '#') error = true;
                        }
                        for (int j = firstX; !error && j <= secondX; ++j) {
                            matrix[j][firstY] = '|';
                        }
                        ok = true;
                    }

                }

                if (!ok || error) {
                    cout << "Error. Enter " << 5 - count << "-cell ship coords (X1 Y1";
                    if (count < 4) cout << " X2 Y2) again:" << endl;
                    else cout << ") again:" << endl;

                    cin >> firstX; cin.clear();
                    cin >> firstY; cin.clear();
                    if (count < 4) {
                        cin >> secondX; cin.clear();
                        cin >> secondY; cin.clear();
                    }
                    else {secondX = firstX; secondY = firstY;}
                }
                if (error) ok = false;
                error = false;
            }
            closeBlocks(closedZone, firstX, firstY, secondX, secondY);
            show(matrix);
        }
        --count;
    }
}

int main() {

    char first[10][10];
    char second[10][10];

    init(first);
    init(second);

    show(first);
    cout << "First player, place your ships." << endl;
    placeShips(first);

    show(second);
    cout << "Second player, place your ships." << endl;
    placeShips(second);

    int winner = game(first, second);

    cout << "The game is over! Player " << winner << " wins!" << endl;

}