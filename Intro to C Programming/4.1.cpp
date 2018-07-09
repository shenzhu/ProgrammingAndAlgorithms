/* Copyright Shen Zhu 2018 */

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int n, x, y;
    while (cin >> n >> x >> y) {
        int eaten_num = y % x == 0 ? y / x : y / x + 1;
        int left = n - eaten_num;
        cout << (left < 0 ? 0 : left) << endl;
    }
    return 0;
}
