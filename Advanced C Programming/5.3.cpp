/* Copyright Shen Zhu 2018 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int a, b, c;
    char comma;
    cin >> a >> comma >> b >> comma >> c;

    if (a + b == c)  {
        cout << "+" << endl;
    } else if (a - b == c) {
        cout << "-" << endl;
    } else if (a * b == c) {
        cout << "*" << endl;
    } else if (a / b == c) {
        cout << "/" << endl;
    } else if (a % b == c) {
        cout << "%" << endl;
    } else {
        cout << "error" << endl;
    }

    return 0;
}