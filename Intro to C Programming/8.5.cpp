/* Copyright Shen Zhu 2018 */

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

bool CheckDivisible(int n) {
    int tenth = n / 10;
    int oneth = n % 10;

    return n % (tenth + oneth) == 0;
}

int main() {
    int n;
    cin >> n;

    for (int i = 10; i <= n; i++) {
        if (CheckDivisible(i)) {
            cout << i << endl;
        }
    }

    return 0;
}
