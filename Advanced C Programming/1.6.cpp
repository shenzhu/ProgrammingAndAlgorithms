/* Copyright Shen Zhu 2018 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    char rooms[100][100];
    int n, m, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> rooms[i][j];
        }
    }
    cin >> m;

    for (int d = 0; d < m; d++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == '!') {
                    rooms[i][j] = '@';
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == '@') {
                    if (i + 1 < n && rooms[i + 1][j] == '.') {
                        rooms[i + 1][j] = '!';
                    }
                    if (j - 1 >= 0 && rooms[i][j - 1] == '.') {
                        rooms[i][j - 1] = '!';
                    }
                    if (j + 1 < n && rooms[i][j + 1] == '.') {
                        rooms[i][j + 1] = '!';
                    }
                    if (i - 1 >= 0 && rooms[i - 1][j] == '.') {
                        rooms[i - 1][j] = '!';
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (rooms[i][j] == '@') {
                sum++;
            }
        }
    }
    cout << sum << endl;

    return 0;
}