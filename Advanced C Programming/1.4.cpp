/* Copyright Shen Zhu 2018 */

#include <iomanip>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::setfill;

bool checkLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)); 
}

int main() {
    int year, month, day;
    char a;
    bool add_day = true;
    cin >> year >> a >> month >> a >> day;
    
    bool leap = checkLeapYear(year);
    if (month == 2) {
        if (leap && day == 29) {
            month++;
            day = 1;
            add_day = false;
        }
        if (!leap && day == 28) {
            month++;
            day = 1;
            add_day = false;
        }
    }

    if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day == 31)) {
        if (month == 12) {
            month = 1;
            day = 1;
            year++;
            add_day = false;
        } else {
            day = 1;
            month++;
            add_day = false;
        }
    }

    if ((month == 4 || month == 6 || month == 9 || month == 11) && (day == 30)) {
        day = 1;
        month++;
        add_day = false;
    }
    
    if (add_day) {
        day++;
    }
    
    cout << year << "-" << setw(2) << setfill('0') << month << "-" << setw(2) << setfill('0') << day << endl;
    return 0;
}
