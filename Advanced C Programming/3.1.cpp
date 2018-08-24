/* Copyright Shen Zhu 2018 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int k;
    cin >> k;

    int m, n;
    int num;
    for (int i = 0; i < k; i++) {
        cin >> m >> n;
        int sum = 0;
        for (int j = 0; j < m; j++) {
            for (int q = 0; q < n; q++) {
                cin >> num;
                if (j == 0 || j == m - 1 || q == 0 || q == n - 1) {
                    sum += num;
                }
            }
        }
        cout << sum << endl;
    }

    return 0;
}