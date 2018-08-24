/* Copyright Shen Zhu 2018 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int row, col;
    int matrix[100][100];
    
    cin >> row >> col;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < row + col - 1; i++) {
        int x = i > col - 1 ? i - col + 1 : 0;
        int y = i - x;
        while (x <= row - 1 && y >= 0) {
            cout << matrix[x][y] << endl;
            x++;
            y--;
        }
    }

    return 0;
}