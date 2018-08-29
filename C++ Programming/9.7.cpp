/*
#include <iostream>
#include <string>
#include <list>
using namespace std;

class A{
private:
        string name;
public:
        A(string n) :name(n){}
        friend bool operator < (const class A& a1, const class A &a2);
        friend bool operator == (const class A &a1, const class A &a2){
                if (a1.name.size() == a2.name.size())
                        return true;
                else
                        return false;
        }
        friend ostream & operator << (ostream &o, const A &a){
                o << a.name;
                return o;
        }
        string get_name() const{
                return name;
        }
        int get_size() const{
                return name.size();
        }
};
*/


inline
bool operator<(const class A& a1, const class A &a2) {
    return a1.get_size() < a2.get_size();
}

class Print {
    public:
        void operator()(A& a) {
            cout << a << " ";
        }
};

template<typename IterType, typename FunctionType>
void Show(IterType begin, IterType end, FunctionType f) {
    for (IterType iter = begin; iter != end; ++iter) {
        f(*iter);
    }
}

template<typename T>
class MyLarge {
    public:
        bool operator()(const T& t1, const T& t2) {
            return t1.get_name() < t2.get_name();
        }
};

/*
int main(int argc, char* argv[])
{
        list<A> lst;
        int ncase, n, i = 1;
        string s;
        cin >> ncase;
        while (ncase--){
                cout << "Case: "<<i++ << endl;
                cin >> n;
                for (int i = 0; i < n; i++){
                         cin >> s;
                         lst.push_back(A(s));
                }
                lst.sort();
                Show(lst.begin(), lst.end(), Print());

                cout << endl;
                lst.sort(MyLarge<A>());
                Show(lst.begin(), lst.end(), Print());
                cout << endl;
                lst.clear();
        }
        return 0;
}
*/