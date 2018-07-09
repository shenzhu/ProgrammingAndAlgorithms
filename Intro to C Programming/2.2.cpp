#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int CalcualteSum(int start, int end) {
    int sum = 0;
    for (int i = start; i <= end; i++) {
        if (i % 2 != 0) sum += i;
    }
    return sum;
}

int main() {
    int m, n;
    while (cin >> m >> n) {
        cout << CalcualteSum(m, n) << endl;
    }
    return 0;
}