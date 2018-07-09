/* Copyright Shen Zhu 2018 */

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int n;
    cin >> n;

    cout << n / 100 << endl;
    cout << n % 100 / 50 << endl;
    cout << n % 100 % 50 / 20 << endl;
    cout << n % 100 % 50 % 20 / 10 << endl;
    cout << n % 100 % 50 % 20 % 10 / 5 << endl;
    cout << n % 100 % 50 % 20 % 10 % 5 / 1 << endl;

    return 0;
}
