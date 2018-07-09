/* Copyright Shen Zhu 2018 */

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int a;
    int curr_num;
    int sum = 0;
    cin >> a;
    for (int i = 0; i < 5; i++) {
        cin >> curr_num;
        if (curr_num < a) sum += curr_num;
    }
    cout << sum << endl;
    return 0;
}
