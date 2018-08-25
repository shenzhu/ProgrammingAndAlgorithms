/* Copyright Shen Zhu 2018 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int CountThree(int num) {
    int count = 0;
    while (num != 0) {
        int remainder = num % 10;
        if (remainder == 3) {
            count++;
        }
        num /= 10;        
    }
    return count;
}

int main() {
    int m, k;
    cin >> m >> k;

    if ((m % 19 == 0) && (CountThree(m) == k)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}