/* Copyright Shen Zhu 2018 */

#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::sort;

struct Bacteria {
    int id;
    int num_before;
    int num_after;
    double growth_rate;

    bool operator<(const Bacteria& lhr) {
        return growth_rate < lhr.growth_rate;
    }
};

int main() {
    int n;
    Bacteria bacs[100];
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> bacs[i].id >> bacs[i].num_before >> bacs[i].num_after;
    }

    for (int i = 0; i < n; i++) {
        bacs[i].growth_rate = (1.0 * (bacs[i].num_after - bacs[i].num_before) / bacs[i].num_before);
    }

    sort(bacs, bacs + n);

    int index = 0;
    double largest_diff = 0.0;
    for (int i = 0; i < n - 1; i++) {
        if (bacs[i + 1].growth_rate - bacs[i].growth_rate > largest_diff) {
            largest_diff = bacs[i + 1].growth_rate - bacs[i].growth_rate;
            index = i;
        }
    }


    cout << n - index - 1 << endl;
    for (int i = index + 1; i < n; i++) {
        cout << bacs[i].id << endl;
    }
    cout << index + 1 << endl;
    for (int i = 0; i <= index; i++) {
        cout << bacs[i].id << endl;
    }

    return 0;
}