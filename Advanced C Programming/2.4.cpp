/* Copyright Shen Zhu 2018 */

#include <iostream>
#include <stack>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::stack;
using std::string;

int main() {
    string line;
    while (cin >> line) {
        string res("");
        stack<char> s;

        for (int i = 0; i < line.length(); i++) {
            if (line[i] == '(') {
                s.push(i);
                res += ' ';
            } else if (line[i] == ')') {
                if (s.empty()) {
                    res += '?';
                } else {
                    res += ' ';
                    s.pop();
                }
            } else {
                res += ' ';
            }
        }

        while (!s.empty()) {
            res[s.top()] = '$';
            s.pop();
        }
        cout << line << endl;
        cout << res << endl;
    }

    return 0;
}
