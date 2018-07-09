/* Copyright Shen Zhu 2018 */

#include <iostream>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int l, m;
    int trees[10001] = {0};
    int segments[100][2];
    cin >> l >> m;
    for (int i = 0; i < m; i++) {
        cin >> segments[i][0] >> segments[i][1];
    }

    for (int i = 0; i < m; i++) {
        for (int j = segments[i][0]; j <= segments[i][1]; j++) {
            trees[j] = 1;
        }
    }

    int counter = 0;
    for (int i = 0; i <= l; i++) {
        if (trees[i] == 0) counter++;
    }

    cout << counter << endl;
    return 0;
}
