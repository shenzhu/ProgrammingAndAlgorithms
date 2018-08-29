/*
#include <iostream>
#include <map>
using namespace std;
*/

class A {
    public:
        static int count;
        int num_;
        A() : num_(0) {
            A::count++; }
        A(int num) : num_(num) {
            A::count++; }
        virtual ~A();
};

inline
A::~A() {
    A::count--;
    cout << "A::destructor" << endl;
}

class B : public A {
    public:
        B() : A() {}
        B(int num) : A(num) {}
        B(const B& b) : A(b.num_) {}
        virtual ~B();
};

inline
B::~B() {
    cout << "B::destructor" << endl;
}

/*
int A::count = 0;
void func(B b) { }
int main()
{
        A a1(5),a2;
        cout << A::count << endl;
        B b1(4);
        cout << A::count << endl;
        func(b1);
        cout << A::count << endl;
        A * pa = new B(4);
        cout << A::count << endl;
        delete pa;
        cout << A::count << endl;
        return 0;
}
*/