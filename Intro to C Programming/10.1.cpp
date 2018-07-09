/* Copyright Shen Zhu 2018 */

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int n;
    cin >> n;
    if (n % 4 == 0) {
        if ((n % 100 == 0 && n % 400 != 0) ||
            (n % 3200 ==0)) {
            cout << "N" << endl;
        } else {
            cout << "Y" << endl;
        }
        return 0;
    } else {
        cout << "N" << endl;
    }

    return 0;
}
