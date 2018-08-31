/* Copyright Shen Zhu 2018 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

bool guess(int puzzle[6][8], int press[6][8]) {
    for (int i = 1; i < 5; i++) {
        for (int j = 1; j < 7; j++) {
            press[i + 1][j] = (puzzle[i][j] + press[i][j] + press[i][j - 1]
                + press[i][j + 1] + press[i - 1][j]) % 2;
        }
    }

    for (int i = 1; i < 7; i++) {
        if ((press[5][i] + press[5][i - 1] + press[5][i + 1]
            + press[4][i]) % 2 != puzzle[5][i]) {
            return false;
        }
    }

    return true;
}

void enumerate(int puzzle[6][8], int press[6][8]) {
    while (!guess(puzzle, press)) {
        press[1][1]++;
        int idx = 1;
        while (press[1][idx] > 1) {
            press[1][idx] = 0;
            idx++;
            press[1][idx]++;
        }
    }
    return;
}

int main() {
    int cases;
    cin >> cases;

    for (int i = 0; i < cases; i++) {
        int puzzle[6][8] = {0}, press[6][8] = {0};
        for (int row = 1; row < 6; row++) {
            for (int col = 1; col < 7; col++) {
                cin >> puzzle[row][col];
            }
        }

        enumerate(puzzle, press);
        cout << "PUZZLE #" << i + 1 << endl;
        for (int row = 1; row < 6; row++) {
            for (int col = 1; col < 7; col++) {
                cout << press[row][col] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
