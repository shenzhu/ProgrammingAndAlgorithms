/* Copyright Shen Zhu 2018 */

#include <iostream>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::sort;

int main() {
    int n, k;
    cin >> n >> k;
    int nums[1000];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums, nums + n);

    int left = 0, right = n - 1;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == k) {
            cout << "yes" << endl;
            return 0;
        } else if (sum < k) {
            left++;
        } else {
            right--;
        }
    }

    cout << "no" << endl;
    return 0;
}
