/* Copyright Shen Zhu 2018 */

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int n;
    cin >> n;

    int distance = 0;
    for (int i = 0; i < n; i++) {
        cin >> distance;
        double bike = 27 + 23 + distance / 3.0;
        double walk = distance / 1.2;
        if (bike > walk) {
            cout << "Walk" << endl;
        } else if (walk > bike) {
            cout << "Bike" << endl;
        } else {
            cout << "All" << endl;
        }
    }

    return 0;
}
