/* Copyright Shen Zhu 2018 */

#include <iomanip>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::scientific;
using std::fixed;

int main() {
    double num;
    cin >> num;

    cout << fixed << setprecision(5) << num << endl;
    cout << scientific << setprecision(7) << num << endl;

    return 0;
}