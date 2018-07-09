/* Copyright Shen Zhu 2018 */

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int a, b;
    char oper;
    while (cin >> a >> b >> oper) {
        switch (oper) {
            case '+': {
                cout << a + b << endl;
                break;
            }
            case '-': {
                cout << a - b << endl;
                break;
            }
            case '*': {
                cout << a * b << endl;
                break;
            }
            case '/': {
                if (b == 0) {
                    cout << "Divided by zero!" << endl;
                } else {
                    cout << a / b << endl;
                }
                break;
            }
            default: {
                cout << "Invalid operator!" << endl;
                break;
            }
        }
    }
    return 0;
}
