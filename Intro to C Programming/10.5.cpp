/* Copyright Shen Zhu 2018 */

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
    string str1, str2;
    while (cin >> str1 >> str2) {
        int max_index = 0;
        char max_char = 'a';
        for (int i = 0; i < str1.length(); i++) {
            if (str1[i] > max_char) {
                max_index = i;
                max_char = str1[i];
            }
        }
        str1.insert(max_index + 1, str2);
        cout << str1 << endl;
    }
    return 0;
}
