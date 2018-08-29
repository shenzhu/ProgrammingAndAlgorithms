/*
#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
*/

class MyString {
    private:
        string str_;

    public:
        MyString() : str_("") {}
        MyString(string str) : str_(str) {}
        MyString(const char* arr) : str_(arr) {}
        MyString(const MyString& rhs) : str_(rhs.str_) {}

        MyString& operator=(const MyString& my_string);
        MyString operator+(const MyString& rhs);
        char& operator[](int idx);
        string operator()(int start, int length);
        bool operator<(const MyString& rhs);
        bool operator==(const MyString& rhs);
        bool operator>(const MyString& rhs);
        MyString& operator+=(const char* arr);

        friend MyString operator+(const char* arr, const MyString& my_string);
        friend ostream& operator<<(ostream& os, const MyString& my_string);
};

inline
MyString& MyString::operator=(const MyString& my_string) {
    this->str_ = my_string.str_;
    return *this;
}

inline
MyString MyString::operator+(const MyString& rhs) {
    MyString res(this->str_ + rhs.str_);
    return res;
}

inline
char& MyString::operator[](int idx) {
    return str_[idx];
}

inline
string MyString::operator()(int start, int length) {
    return this->str_.substr(start, length);
}

inline
bool MyString::operator<(const MyString& rhs) {
    return this->str_ < rhs.str_;
}

inline
bool MyString::operator==(const MyString& rhs) {
    return this->str_ == rhs.str_;
}

inline
bool MyString::operator>(const MyString& rhs) {
    return this->str_ > rhs.str_;
}

inline
MyString& MyString::operator+=(const char* arr) {
    this->str_ += string(arr);
    return *this;
}

inline
MyString operator+(const char* arr, const MyString& my_string) {
    string cast_str(arr);
    return MyString(cast_str + my_string.str_);
}

inline
ostream& operator<<(ostream& os, const MyString& my_string) {
    os << my_string.str_;
    return os;
}

/*
int CompareString( const void * e1, const void * e2)
{
        MyString * s1 = (MyString * ) e1;
        MyString * s2 = (MyString * ) e2;
        if( * s1 < *s2 )
                 return -1;
        else if( *s1 == *s2)
                 return 0;
        else if( *s1 > *s2 )
                 return 1;
}
int main()
{
        MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
        MyString SArray[4] = {"big","me","about","take"};
        cout << "1. " << s1 << s2 << s3<< s4<< endl;
        s4 = s3;
        s3 = s1 + s3;
        cout << "2. " << s1 << endl;
        cout << "3. " << s2 << endl;
        cout << "4. " << s3 << endl;
        cout << "5. " << s4 << endl;
        cout << "6. " << s1[2] << endl;
        s2 = s1;
        s1 = "ijkl-";
        s1[2] = 'A' ;
        cout << "7. " << s2 << endl;
        cout << "8. " << s1 << endl;
        s1 += "mnop";
        cout << "9. " << s1 << endl;
        s4 = "qrst-" + s2;
        cout << "10. " << s4 << endl;
        s1 = s2 + s4 + " uvw " + "xyz";
        cout << "11. " << s1 << endl;
        qsort(SArray,4,sizeof(MyString),CompareString);
        for( int i = 0;i < 4;i ++ )
        cout << SArray[i] << endl;
        //s1的从下标0开始长度为4的子串
        cout << s1(0,4) << endl;
        //s1的从下标5开始长度为10的子串
        cout << s1(5,10) << endl;
        return 0;
}
*/