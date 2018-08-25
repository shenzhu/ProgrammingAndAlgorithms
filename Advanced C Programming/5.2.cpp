/* Copyright Shen Zhu 2018 */

#include <iostream>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::tolower;
using std::toupper;
using std::isalpha;

int main() {
    string str;
    cin >> str;

    int char_counts[26] = {0};
    for (size_t i = 0; i < str.length(); i++) {
        if (isalpha(str[i])) {
            char_counts[tolower(str[i]) - 'a']++;
        }
    }

    int max_count = -1, second_max_count = -1;
    for (size_t i = 0; i < 26; i++) {
        if (char_counts[i] > max_count) {
            second_max_count = max_count;
            max_count = char_counts[i];
        } else if (char_counts[i] > second_max_count) {
            if (char_counts[i] != max_count) {
                second_max_count = char_counts[i];
            }
        }
    }

    for (size_t i = 0; i < str.length(); i++) {
        if (isalpha(str[i]) && char_counts[tolower(str[i]) - 'a'] == second_max_count) {
            cout << static_cast<char>(toupper(str[i])) << "+"
                 << static_cast<char>(tolower(str[i])) << ":"
                 << char_counts[tolower(str[i]) - 'a'] << endl;
            break;
        }
    }

    return 0;
}