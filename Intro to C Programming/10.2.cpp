/* Copyright Shen Zhu 2018 */

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int n;
    while (cin >> n) {
        bool three = false, five = false, seven = false;
        if (n % 3 == 0) three = true;
        if (n % 5 == 0) five = true;
        if (n % 7 == 0) seven = true;

        if (three) cout << "3 ";
        if (five) cout << "5 ";
        if (seven) cout << 7;
        if (!three && !five && !seven) cout << "n";
        cout << endl;
    }

    return 0;
}
