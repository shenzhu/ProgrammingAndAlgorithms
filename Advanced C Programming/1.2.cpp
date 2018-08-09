/* Copyright Shen Zhu 2018 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            for (int k = 1; k <= 4; k++) {
                for (int l = 1; l <= 4; l++) {
                    if (i != j && i != k && i != l && j != k && j != l && k != l) {
                        if (((j == 1) + (l == 4) + (i == 3)) == 1 &&
                            ((l == 1) + (j == 4) + (i == 2) + (k == 3)) == 1 &&
                            ((l == 4) + (j == 3)) == 1 &&
                            ((i == 1) + (k == 4) + (l == 2) + (j == 3)) == 1) {
                                cout << i << endl;
                                cout << j << endl;
                                cout << k << endl;
                                cout << l << endl;
                                break;
                        }
                    }
                }
            }
        }
    }
    return 0;
}