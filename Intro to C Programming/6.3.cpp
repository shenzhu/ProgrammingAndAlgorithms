/* Copyright Shen Zhu 2018 */

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int partition(int arr[], int left, int right) {
    int pivot = arr[left];
    int i = left + 1, j = right;

    while (true) {
        while (i < right && arr[i] < pivot) i++;
        while (left < j && arr[j] > pivot) j--;
        if (i >= j) break;
        swap(arr, i++, j--);
    }
    swap(arr, left, j);
    return j;
}

int main() {
    int n, k;
    cin >> n >> k;
    int nums[100];

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    k = n - k;
    int left = 0, right = n - 1;
    while (left < right) {
        int idx = partition(nums, left, right);
        if (idx < k) {
            left = idx + 1;
        } else if (idx > k) {
            right = idx - 1;
        } else {
            break;
        }
    }

    cout << nums[k] << endl;
    return 0;
}
