/* Copyright Shen Zhu 2018 */

#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int n;
    int nums[100];
    bool found = false;
    while (cin >> n) {
        found = false;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] == i) {
                cout << nums[i] << endl;
                found = true;
                break;
            }
        }

        if (!found) cout << "N" << endl;
    }

    return 0;
}
