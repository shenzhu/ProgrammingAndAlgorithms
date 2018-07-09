/* Copyright Shen Zhu 2018 */

#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw;

int main() {
    int matrix[5][5];
    int n, m;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> matrix[i][j];
        }
    }
    cin >> n >> m;

    if ((n < 0 || n > 4) || (m < 0 || m > 4)) {
        cout << "error" << endl;
        return 0;
    }

    for (int i = 0; i < 5; i++) {
        int temp = matrix[n][i];
        matrix[n][i] = matrix[m][i];
        matrix[m][i] = temp;
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }

    return 0;
}
