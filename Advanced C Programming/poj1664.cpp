/* Copyright Shen Zhu 2018 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int CountApple(int m, int n) {
    if (m <= 1 || n <= 1) return 1;
    if (n > m) {
        return CountApple(m, m);
    } else {
        return CountApple(m, n - 1) + CountApple(m - n, n);
    }
}

int main() {
    int t;
    int m, n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> m >> n;
        cout << CountApple(m, n) << endl;
    }

    return 0;
}