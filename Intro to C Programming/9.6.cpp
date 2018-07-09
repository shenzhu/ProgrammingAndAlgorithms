/* Copyright Shen Zhu 2018 */

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void reverse(int nums[], int i, int j) {
    while (i < j) {
        int temp = nums[i];
        nums[i++] = nums[j];
        nums[j--] = temp;
    }
}

int main() {
    int n, m;
    int nums[100];
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    reverse(nums, 0, n - 1);
    reverse(nums, 0, m - 1);
    reverse(nums, m, n - 1);

    for (int i = 0; i < n; i++) {
        cout << nums[i];
        if (i != n - 1) cout << " ";
    }

    return 0;
}
