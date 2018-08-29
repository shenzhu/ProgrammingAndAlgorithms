/* Copyright Shen Zhu 2018 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::hex;

int main() {
    int n;
    cin >> n;

    while (n--) {
        int num, i, j;
        cin >> num >> i >> j;

        int result = 0;
        if (num & (1 << i)) {
            result |= 1 << i;
        }
        if (!(num & (1 << j))) {
            result |= 1 << j;
        }

        for (int k = i + 1; k < j; k++) {
            result |= 1 << k;
        }

        cout << hex << result << endl;
    }

    return 0;
}