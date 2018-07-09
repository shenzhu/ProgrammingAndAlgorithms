#include <iostream>

using std::cout;
using std::cin;
using std::endl;

const int maxn = 100;

int main() {
    int k;
    int nums[100] = {0};
    while (cin >> k) {
        for (int i = 0; i < k; i++) {
            cin >> nums[i];
        }

        int num_counts[3] = {0};
        for (int i = 0; i < k; i++) {
            if (nums[i] == 1) num_counts[0]++;
            if (nums[i] == 5) num_counts[1]++;
            if (nums[i] == 10) num_counts[2]++;
        }

        cout << num_counts[0] << endl;
        cout << num_counts[1] << endl;
        cout << num_counts[2] << endl;
    }
    return 0;
}