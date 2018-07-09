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
    int counts[5] = {0};

    for (int i = 0; i < line.length(); i++) {
        if (line[i] == 'a') counts[0]++;
        else if (line[i] == 'e') counts[1]++;
        else if (line[i] == 'i') counts[2]++;
        else if (line[i] == 'o') counts[3]++;
        else if (line[i] == 'u') counts[4]++;
    }

    for (int i = 0; i < 5; i++) {
        cout << counts[i];
        if (i != 4) {
            cout << " ";
        }
    }

    return 0;
}
