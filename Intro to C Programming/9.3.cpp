/* Copyright Shen Zhu 2018 */

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;

int main() {
    string line;
    getline(cin, line);

    int slow = 0, fast = 0;
    int max_length = -1;
    string word = "";

    while (line[fast] != '.') {
        if (line[fast] == ' ') {
            int curr_length = fast - slow;
            if (curr_length > max_length) {
                max_length = curr_length;
                word = line.substr(slow, curr_length);
            }
            slow = fast + 1;
        }
        fast++;
    }

    int curr_length = fast - slow;
    if (curr_length > max_length) {
        cout << line.substr(slow, curr_length) << endl;
    } else {
        cout << word << endl;
    }

    return 0;
}
