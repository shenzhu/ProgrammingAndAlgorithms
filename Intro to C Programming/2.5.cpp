#include <iostream>

using std::cout;
using std::cin;
using std::endl;

const int maxn = 100;

int main() {
    int n;
    int nums[maxn] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        cout << nums[i];
        if (i > 0) cout << " ";
    }
    return 0;
}
