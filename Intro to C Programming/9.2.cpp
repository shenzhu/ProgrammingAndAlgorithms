/* Copyright Shen Zhu 2018 */

#include <iostream>
#include <string>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::transform;

int main() {
    string str1, str2;
    while (cin >> str1 >> str2) {
        transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
        transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
        int res = str1.compare(str2);
        if (res == 0) {
            cout << "=" << endl;
        } else if (res > 0) {
            cout << ">" << endl;
        } else {
            cout << "<" << endl;
        }
    }
    return 0;
}
