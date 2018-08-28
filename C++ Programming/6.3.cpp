/* Copyright Shen Zhu 2018 */

#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::dec;
using std::endl;
using std::hex;
using std::setw;

int main() {
    int num;
    cin >> num;

    cout << hex << num << endl;

    cout.fill('0');
    cout << dec << setw(10) << num << endl;

    return 0;
}