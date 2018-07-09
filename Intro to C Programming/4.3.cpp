/* Copyright Shen Zhu 2018 */

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int n;
    cin >> n;
    int score = 0;
    int highest_score = -1;
    for (int i = 0; i < n; i++) {
        cin >> score;
        if (score > highest_score) {
            highest_score = score;
        }
    }

    cout << highest_score << endl;

    return 0;
}
