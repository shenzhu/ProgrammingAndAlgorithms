/* Copyright Shen Zhu 2018 */

#include <iostream>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::sort;

int main() {
    int n;
    int nums[15000];
    while (cin >> n && n != 0) {
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        sort(nums, nums + n);

        if (n % 2 != 0) {
            cout << nums[n / 2] << endl;
        } else {
            cout << (nums[n / 2] + nums[n / 2 - 1]) / 2 << endl;
        }
    }

    return 0;
}
