/* Copyright Shen Zhu 2018 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    char words[1000][40];  // Store all words
    int words_len[1000];  // Store length of all words
    int n;

    cin >> n;
    cin.get();  // Use cin.get() to eat '\n' after n

    for (int i = 0; i < n; i++) {
		char temp;
		for (int j = 0; j < 40; j++) {
			cin.get(temp);
			if (temp != ' ' && temp != '\n') {
				words[i][j] = temp;
			}
			else {
				words_len[i] = j;
				break;
			}
		}
	}

    // Output the first word
	int length = words_len[0];
	for (int i = 0; i < length; i++) {
		cout << words[0][i];
	}

	for (int i = 1; i < n; i++) {
		if (length + 1 + words_len[i] <= 80) {
			length = length + 1 + words_len[i];
			cout << ' ';
			for (int j = 0; j < words_len[i]; j++) {
				cout << words[i][j];
			}
		}
		else {
			length = words_len[i];
			cout << endl;
			for (int j = 0; j < length; j++) {
				cout << words[i][j];
            }
        }
    }

    return 0;
}
