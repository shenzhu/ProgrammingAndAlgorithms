/* Copyright Shen Zhu 2018 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::unordered_map;

int main() {
    int n;
    cin >> n;

    // Read inputs
    vector<string> dna;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        dna.push_back(str);
    }

    unordered_map<char, char> dna_map;
    dna_map['A'] = 'T';
    dna_map['T'] = 'A';
    dna_map['G'] = 'C';
    dna_map['C'] = 'G';

    for (int i = 0; i < n; i++) {
        string complement = dna[i];
        for (int j = 0; j < complement.length(); j++) {
            complement[j] = dna_map[complement[j]];
        }
        cout << complement << endl;
    }

    return 0;
}