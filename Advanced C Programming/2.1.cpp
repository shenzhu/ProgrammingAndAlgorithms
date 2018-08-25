/* Copyright Shen Zhu 2018 */

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;

void ReverseString(char word[], int i) {
    if (word[i] == '\0') {
        return;
    } else {
        ReverseString(word, i + 1);
        cout << word[i];
    }
}

int main() {
    string line;
    char word[501];
    getline(cin, line);

    int j = 0;
    for (int i = 0; i < line.length(); i++) {
        if (line[i] != ' ') {
            word[j] = line[i];
            j++;
        } else {
            word[j] = '\0';
            ReverseString(word, 0);
            cout << " ";
            j = 0;
        }
    }
    word[j] = '\0';
    ReverseString(word, 0);
    cout << endl;

    return 0;
}
