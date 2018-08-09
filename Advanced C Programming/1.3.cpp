/* Copyright Shen Zhu 2018 */

#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

int main() {
    double people[3] = {0.0};
    double ticket[3] = {0.0};
    int curr_people;
    int ticket_num;
    for (int i = 0; i < 3; i++) {
        cin >> curr_people >> ticket_num;
        char ticket_type;
        double amount;
        for (int j = 0; j < ticket_num; j++) {
            cin >> ticket_type >> amount;
            ticket[ticket_type - 'A'] += amount;
            people[curr_people - 1] += amount;
        }
    }
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << " " << fixed << setprecision(2) << people[i] << endl;
    }
    for (int i = 0; i < 3; i++) {
        cout << static_cast<char>('A' + i) << " " << fixed << setprecision(2) << ticket[i] << endl;
    }
    return 0;
}