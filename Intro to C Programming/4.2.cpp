/* Copyright Shen Zhu 2018 */

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

const double PI = 3.14159;

int main() {
    int h, r;
    double V = 0.0;
    while (cin >> h >> r) {
        V = PI * r * r * h;
        int counter = 0;
        double sum = 0.0;
        while (sum < 20000) {
            sum += V;
            counter++;
        }
        cout << counter << endl;
    }
    return 0;
}
