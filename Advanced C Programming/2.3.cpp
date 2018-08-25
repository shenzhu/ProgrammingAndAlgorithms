/* Copyright Shen Zhu 2018 */

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int PrintMatch(const string& line, int start, char special_char) {
    if (line[start] != special_char) {
        return start;
    } else {
        int n = PrintMatch(line, start + 1, special_char);
        cout << start << " " << n << endl;
        return PrintMatch(line, n + 1, special_char);
    }
}

int main() {
    string line;
    char special_char;

    cin >> line;
    special_char = line[0];

    int n = PrintMatch(line, 1, special_char);
    cout << "0 " << n << endl;

    return 0;
}
