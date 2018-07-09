/* Copyright Shen Zhu 2018 */
/* Takeaway: bool operator can be used as 1 or 0 when +/- */

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int best;
    for (best = 1; best <= 4; best++) {
        bool a = (best == 2);
        bool b = (best == 4);
        bool c = !(best == 3);
        bool d = !b;

        if (a + b + c + d != 1) continue;

        cout << best << endl;
        if ( a == 1)
            cout << "A" << endl;
        else if ( b == 1)
            cout << "B" << endl;
        else  if ( c == 1)
            cout << "C" << endl;
        else
            cout << "D" << endl;
    }
    return 0;
}
