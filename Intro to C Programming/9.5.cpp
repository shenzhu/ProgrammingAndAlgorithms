/* Copyright Shen Zhu 2018 */

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int n;
    int matrix[100][100] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int counter = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (matrix[i][j - 1] - matrix[i][j] >= 50 &&
                matrix[i][j + 1] - matrix[i][j] >= 50 &&
                matrix[i - 1][j] - matrix[i][j] >= 50 &&
                matrix[i + 1][j] - matrix[i][j] >= 50) {
                counter++;
            }
        }
    }

    cout << counter << endl;
    return 0;
}
