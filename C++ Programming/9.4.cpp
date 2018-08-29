/*
#include <iostream>
using namespace std;
*/

class CType {
    private:
        int num_;
    public:
        void setvalue(int num) {
            num_ = num;
        }

        CType operator++(int) {
            CType c_type;
            c_type.num_ = this->num_;

            this->num_ = this->num_ * this->num_;
            return c_type;
        }

        friend ostream& operator<<(ostream& os, const CType& c_type);
};

inline
ostream& operator<<(ostream& os, const CType& c_type) {
    os << c_type.num_;
    return os;
}

/*
int main(int argc, char* argv[]) {
        CType obj;
        int n;
        cin>>n;
        while ( n ) {
                obj.setvalue(n);
                cout<<obj++<<" "<<obj<<endl;
                cin>>n;
        }
        return 0;
}
*/