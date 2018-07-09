/* Copyright Shen Zhu 2018 */

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int N, K;
    while (cin >> N >> K) {
        double housing_price = 200;
        int m;
        for (m = 1; m <= 20; m++) {
            double pay = m * N;
            if (pay > housing_price) {
                cout << m << endl;
                break;
            }

            housing_price *= (1 + K / 100.0);
        }

        if (m > 20) {
            cout << "Impossible" << endl;
        }
    }
    return 0;
}
