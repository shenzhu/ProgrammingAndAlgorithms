#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int n;
    while (cin >> n) {
        if (n == 1 || n == 3 || n == 5) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}