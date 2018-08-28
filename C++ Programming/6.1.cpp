/*
#include <iostream>
using namespace std;
*/

template <typename T>
class CArray3D {
private:
	T*** num;
public:
	CArray3D() {};
	CArray3D(int a, int b, int c) {
		num = new T**[a];
		for (int i = 0; i < a; i++) {
			num[i] = new T*[b];
			for (int j = 0; j < b; j++) {
				num[i][j] = new T[c];
			}
		}
	}

	T** operator[](int i) {
		return num[i];
	}
};

/*
int main()
{
    CArray3D<int> a(3,4,5);
    int No = 0;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                a[i][j][k] = No ++;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                cout << a[i][j][k] << ",";
return 0;
}
*/