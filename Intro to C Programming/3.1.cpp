#include <iostream>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::sort;

struct Bacteria {
    int id;
    double growth_rate;

    bool operator<(const Bacteria& other) const {
        return growth_rate > other.growth_rate;
    }
};

int main() {
    int n;
    cin >> n;
    Bacteria bacs[100];

    int id, curr_num, future_num;
    for (int i = 0; i < n; i++) {
        cin >> id >> curr_num >> future_num;
        bacs[i].id = id;
        bacs[i].growth_rate = (future_num - curr_num) * 1.0 / curr_num;
    }

    sort(bacs, bacs + n);

    double max_diff = 0;
    int index = 0;
    for (int i = 0; i < n - 1; i++) {
        double curr_diff = bacs[i].growth_rate - bacs[i + 1].growth_rate;
        if (curr_diff > max_diff) {
            max_diff = curr_diff;
            index = i;
        }
    }

    cout << index + 1 << endl;
    for (int i = index; i >= 0; i--) {
        cout << bacs[i].id << endl;
    }

    cout << n - index - 1 << endl;
    for (int i = n - 1; i > index; i--) {
        cout << bacs[i].id << endl;
    }

    return 0;
}
