/* Copyright Shen Zhu 2018 */

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int n;
    cin >> n;
    cout << n / 100 << endl;
    cout << n % 100 / 10 << endl;
    cout << n % 10 << endl;

    return 0;
}