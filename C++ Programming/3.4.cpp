/* Copyright Shen Zhu 2018 */

#include <algorithm>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::reverse;
using std::string;

class BigInt {
 private:
  string values;
  bool flag;

 public:
  BigInt() : values("0"), flag(true) {}
  explicit BigInt(string str);

  int compare(string s1, string s2);

  BigInt operator+(const BigInt& rhs);
  BigInt operator-(const BigInt& rhs);
  BigInt operator*(const BigInt& rhs);
  BigInt operator/(const BigInt& rhs);

  friend ostream& operator<<(ostream& os, const BigInt& big_int);
  friend istream& operator>>(istream& is, BigInt& big_int);
};

inline
BigInt::BigInt(string str) {
    values = str;
    flag = true;
}

inline
int BigInt::compare(string s1, string s2) {
    if (s1.length() < s2.length()) {
        return -1;
    } else if (s1.length() > s2.length()) {
        return 1;
    } else {
        return s1.compare(s2);
    }
}

inline
BigInt BigInt::operator+(const BigInt& rhs) {
    BigInt res;
    string lvalues(values), rvalues(rhs.values);

    // Corner case
    if (lvalues == "0") {
        res.values = rvalues;
        return res;
    }

    if (rvalues == "0") {
        res.values = lvalues;
        return res;
    }

    int lsize = lvalues.size();
    int rsize = rvalues.size();
    if (lsize < rsize) {
        for (int i = 0; i < rsize - lsize; i++) {
            lvalues = "0" + lvalues;
        }
    } else {
        for (int i = 0; i < lsize - rsize; i++) {
            rvalues = "0" + rvalues;
        }
    }

    int sum = 0, carry = 0;
    int size = lvalues.size();
    string res_str("");

    reverse(lvalues.begin(), lvalues.end());
    reverse(rvalues.begin(), rvalues.end());

    for (int i = 0; i < size; i++) {
        sum = (lvalues[i] - '0' + rvalues[i] - '0' + carry) % 10;
        carry = (lvalues[i] - '0' + rvalues[i] - '0' + carry) / 10;
        res_str = res_str + static_cast<char>(sum + '0');
    }

    if (carry == 1) {
        res_str = res_str + "1";
    }
    reverse(res_str.begin(), res_str.end());

    res.values = res_str;
    return res;
}

inline
BigInt BigInt::operator-(const BigInt& rhs) {
    BigInt result;
    string lvalues(values), rvalues(rhs.values);

    if (rvalues == "0") {
        result.values = lvalues;
        return result;
    }
    if (lvalues == "0") {
        result.values = rvalues;
        result.flag = false;
        return result;
    }

    int lsize = lvalues.length();
    int rsize = rvalues.length();

    if (lsize < rsize) {
        for (int i = 0; i < rsize - lsize; i++) {
            lvalues = "0" + lvalues;
        }
    } else {
        for (int i = 0; i < lsize - rsize; i++) {
            rvalues = "0" + rvalues;
        }
    }

    // Check which one is larger
    int compare_res = lvalues.compare(rvalues);
    if (compare_res < 0) {
        result.flag = false;
        string temp = lvalues;
        lvalues = rvalues;
        rvalues = temp;
    } else if (compare_res == 0) {
        result.values = "0";
        result.flag = true;
        return result;
    } else {
        result.flag = true;
    }

    int size = lvalues.size();
    string res_str("");

    reverse(lvalues.begin(), lvalues.end());
    reverse(rvalues.begin(), rvalues.end());

    for (int i = 0; i < size; i++) {
        if (lvalues[i] < rvalues[i]) {
            int j = 1;
            while (lvalues[i + j] == '0') {
                lvalues[i + j] = '9';
                j++;
            }
            lvalues[i + j] -= 1;
            res_str = res_str +
                      static_cast<char>(lvalues[i] + ':' - rvalues[i]);
        } else {
            res_str = res_str +
                      static_cast<char>(lvalues[i] - rvalues[i] + '0');
        }
    }

    reverse(res_str.begin(), res_str.end());
    res_str.erase(0, res_str.find_first_not_of('0'));

    result.values = res_str;
    return result;
}

inline
BigInt BigInt::operator*(const BigInt& rhs) {
    BigInt result;
    string lvalues(values), rvalues(rhs.values);

    if (lvalues == "0" || rvalues == "0") {
        result.values = "0";
        result.flag = false;
        return result;
    }

    int lsize = lvalues.size();
    int rsize = rvalues.size();
    if (lsize < rsize) {
        string temp = lvalues;
        lvalues = rvalues;
        rvalues = temp;
        lsize = lvalues.size();
        rsize = rvalues.size();
    }

    reverse(lvalues.begin(), lvalues.end());
    reverse(rvalues.begin(), rvalues.end());

    for (int i = 0; i < rsize; i++) {
        string temp("");
        for (int j = 0; j < i; j++) {
            temp = temp + "0";
        }
        int curr_digit = rvalues[i] - '0';
        int left = 0, carry = 0;
        for (int j = 0; j < lsize; j++) {
            int sum = (curr_digit * (lvalues[j] - '0') + carry);
            left = sum % 10;
            carry = sum / 10;
            temp = temp + static_cast<char>(left + '0');
        }

        if (carry) {
            temp = temp + static_cast<char>(carry + '0');
        }

        reverse(temp.begin(), temp.end());
        BigInt big_temp;
        big_temp.values = temp;

        result = result + big_temp;
    }

    return result;
}

inline
BigInt BigInt::operator/(const BigInt& rhs) {
    BigInt result;
    string lvalues(values), rvalues(rhs.values);
    string quotient;

    if (rvalues == "0") {
        result.values = "error";
        result.flag = true;
        return result;
    }
    if (lvalues == "0") {
        result.values = "0";
        result.flag = true;
        return result;
    }

    if (compare(lvalues, rvalues) < 0) {
        result.values = "0";
        result.flag = true;
        return result;
    } else if (compare(lvalues, rvalues) == 0) {
        result.values = "1";
        result.flag = true;
        return result;
    } else {
        int lsize = lvalues.size();
        int rsize = rvalues.size();
        string temp;

        if (rsize > 1) temp.append(lvalues, 0, rsize - 1);
        for (int i = rsize - 1; i < lsize; i++) {
            temp = temp + lvalues[i];

            for (char c = '9'; c >= '0'; c--) {
                BigInt t = (BigInt)rvalues * (BigInt)string(1, c);
                BigInt s = (BigInt)temp - t;

                if (s.flag) {
                    temp = s.values;
                    quotient = quotient + c;
                    break;
                }
            }
        }
    }

    quotient.erase(0, quotient.find_first_not_of('0'));
    result.values = quotient;
    result.flag = true;

    return result;
}

ostream& operator<<(ostream& os, const BigInt& big_int) {
    if (!big_int.flag) {
        os << "-";
    }
    os << big_int.values;
    return os;
}

istream& operator>>(istream& is, BigInt& big_int) {
    string str;
    is >> str;
    big_int.values = str;
    big_int.flag = true;
    return is;
}

int main() {
    BigInt a, b, result;
    char op;
    cin >> a >> op >> b;
    switch (op) {
        case '+': result = a + b; break;
        case '-': result = a - b; break;
        case '*': result = a * b; break;
        case '/': result = a / b; break;
        default: break;
    }
    cout << result << endl;
    return 0;
}
