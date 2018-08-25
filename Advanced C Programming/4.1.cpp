/* Copyright Shen Zhu 2018 */

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::sort;
using std::setprecision;
using std::fixed;

struct Patient {
    string id;
    double severity;

    bool operator<(const Patient& rhs) {
        return rhs.severity < severity;
    }
};

int main() {
    int m;
    double criterion;
    cin >> m >> criterion;

    Patient patients[50];
    for (int i = 0; i < m; i++) {
        cin >> patients[i].id >> patients[i].severity;
    }

    sort(patients, patients + m);

    int count = 0;
    for (int i = 0; i < m; i++) {
        if (patients[i].severity < criterion) break;
        cout << patients[i].id << " " << fixed << setprecision(1) << patients[i].severity << endl;
        count++;
    }

    if (count == 0) cout << "None." << endl;

    return 0;
}