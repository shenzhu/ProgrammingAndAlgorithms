/*
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
*/
    Complex& operator=(const string& str) {
    	int pos = str.find("+", 0);
    	string real_temp = str.substr(0, pos);
    	string virtual_temp = str.substr(pos + 1, str.length() - pos - 1);
    	r = atoi(real_temp.c_str());
    	i = atoi(virtual_temp.c_str());
    	return *this;
    }
/*
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}
*/