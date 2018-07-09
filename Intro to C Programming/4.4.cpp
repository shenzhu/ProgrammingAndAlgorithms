/* Copyright Shen Zhu 2018 */

#include <iostream>
#include <limits>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int max_odd = std::numeric_limits<int>::min();
    int min_even = std::numeric_limits<int>::max();

    int num;
    for (int i = 0; i < 6; i++) {
        cin >> num;
        if (num % 2 == 0) {
            if (num < min_even) {
                min_even = num;
            }
        } else {
            if (num > max_odd) {
                max_odd = num;
            }
        }
    }

    cout << abs(min_even - max_odd) << endl;
    return 0;
}
