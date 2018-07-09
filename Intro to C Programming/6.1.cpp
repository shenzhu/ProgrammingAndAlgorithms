/* Copyright Shen Zhu 2018 */

/*
Takeout: fixed and setprecision only works on floating number
*/

#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::fixed;
using std::setprecision;

int main() {
    int n;
    cin >> n;
    int counts[4] = {0};
    int curr_num;

    for (int i = 0; i < n; i++) {
        cin >> curr_num;
        if (curr_num <= 18) {
            counts[0]++;
        } else if (curr_num <= 35) {
            counts[1]++;
        } else if (curr_num <= 60) {
            counts[2]++;
        } else {
            counts[3]++;
        }
    }

    cout << "1-18: " << fixed << setprecision(2)
         << counts[0] * 100.0 / n << "%" << endl;
    cout << "19-35: " << fixed << setprecision(2)
         << counts[1] * 100.0 / n << "%" << endl;
    cout << "36-60: " << fixed << setprecision(2)
         << counts[2] * 100.0 / n << "%" << endl;
    cout << "60-: " << fixed << setprecision(2)
         << counts[3] * 100.0 / n << "%" << endl;

    return 0;
}
