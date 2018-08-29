/*
#include<iostream>
using namespace std;
class Number {
public:
    int num;
    Number(int n=0): num(n) {}
*/

    Number& operator=(const Number& rhs) {
        num = rhs.num;
        return *this;
    }
    operator int() {
        return num;
    }
    Number operator*(const Number& rhs) {
        Number n(this->num * rhs.num);
        return n;
    }

/*
};

int main() {
    Number n1(10), n2(20);
    Number n3;n3 = n1*n2;
    cout << int(n3) << endl;
    return 0;
}
*/