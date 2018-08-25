/* Copyright Shen Zhu 2018 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void CollatzConjecture(int num) {
    if (num == 1) return;
    if (num % 2 == 0) {
        cout << num << "/2=" << num / 2 << endl;
        CollatzConjecture(num / 2);
    } else {
        cout << num << "*3+1=" << num * 3 + 1 << endl;
        CollatzConjecture(num * 3 + 1);
    }
}

int main() {
    int n;
    cin >> n;

    CollatzConjecture(n);
    cout << "End" << endl;

    return 0;
}
