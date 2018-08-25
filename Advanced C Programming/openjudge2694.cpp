/* Copyright Shen Zhu 2018 */

#include <iostream>
#include <cstdio>
#include <cstdlib>

using std::atof;
using std::cin;
using std::printf;

double notation() {
    char a[10];
    cin >> a;
    switch(a[0]) {
        case '+': return notation() + notation();
        case '-': return notation() - notation();
        case '*': return notation() * notation();
        case '/': return notation() / notation();
        default: return atof(a);
    }
}

int main() {
    printf("%f\n", notation());
    return 0;
}