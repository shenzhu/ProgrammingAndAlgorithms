/*
#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;
*/

class A {
    public:
        char type_;
        int age_;

        A(int age) : age_(age), type_('A') {}
        A(char type, int age) : type_(type), age_(age) {}
};

class B : public A {
    public:
        B(int age) : A('B', age) {}
};

class Comp {
    public:
        bool operator()(const A* a1, const A* a2) {
            return a1->age_ < a2->age_;
        }
};

void Print(const A* a) {
    cout << a->type_ << " " << a->age_ << endl;
}

/*
int main()
{

        int t;
        cin >> t;
        set<A*,Comp> ct;
        while( t -- ) {
                int n;
                cin >> n;
                ct.clear();
                for( int i = 0;i < n; ++i)	{
                        char c; int k;
                        cin >> c >> k;

                        if( c == 'A')
                                ct.insert(new A(k));
                        else
                                ct.insert(new B(k));
                }
                for_each(ct.begin(),ct.end(),Print);
                cout << "****" << endl;
        }
}
*/