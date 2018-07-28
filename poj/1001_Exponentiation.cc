// 1001_Exponentiation

// Description
// Problems involving the computation of exact values of very large magnitude
// and precision are common. For example, the computation of the national debt
// is a taxing experience for many computer systems. This problem requires that
// you write a program to compute the exact value of Rn where R is a real number
// (0.0 < R < 99.999) and n is an integer such that 0 < n <= 25.

// Input
// The input will consist of a set of pairs of values for R and n. The R value
// will occupy columns 1 through 6, and the n value will be in columns 8 and 9.

// Output
// The output will consist of one line for each line of input giving the exact
// value of R^n. Leading zeros should be suppressed in the output. Insignificant
// trailing zeros must not be printed. Don't print the decimal point if the
// result is an integer.
//
// Sample Input
// 95.123 12
// 0.4321 20
// 5.1234 15
// 6.7592  9
// 98.999 10
// 1.0100 12

// Sample Output
// 548815620517731830194541.899025343415715973535967221869852721
// .00000005148554641076956121994511276767154838481760200726351203835429763013462401
// 43992025569.928573701266488041146654993318703707511666295476720493953024
// 29448126.764121021618164430206909037173276672
// 90429072743629540498.107596019456651774561044010001
// 1.126825030131969720661201

// HACK: 所有的输入都有小数点，所以实际上只会有五位数

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::reverse;
using std::string;
using std::stringstream;
using std::vector;

class BigNumber {
public:
    // 倒序存储方便运算
    vector<int> rev;
    // 存放小数点位置（从后往前算）
    // 例如原来的数字是 22.222，dots = 3
    unsigned rev_dot;

    BigNumber();
    BigNumber(const string & num);
    BigNumber(const unsigned length, const unsigned d);
    BigNumber(const BigNumber &original);
    BigNumber &operator=(const BigNumber &original); 
    string toString();
    ~BigNumber();
};

BigNumber operator*(const BigNumber &a, const BigNumber &b);
BigNumber pow(const BigNumber &base, unsigned exponent);

int main() {
    std::ios::sync_with_stdio(false);
    string string_base;
    int times;
    while (cin >> string_base >> times) {
        BigNumber base(string_base);
        cout << pow(base, times).toString() << endl;
    }
    return 0;
}

BigNumber::BigNumber(const string & number) {
    rev.resize(6, 0);
    rev_dot = 0;
    int j = 0;
    for (int i = 5; i != -1; --i) {
        if (number[i] != '.') {
            rev[j] = number[i] - '0';
            ++j;
        } else {
            rev_dot = 5 - i;
        }
    }
}

BigNumber::BigNumber(const unsigned length, const unsigned d) {
    rev.resize(length, 0);
    rev_dot = d;
}

BigNumber::BigNumber(const BigNumber &original) : rev(original.rev),
    rev_dot(original.rev_dot) {}

BigNumber &BigNumber::operator=(const BigNumber &original) {
    rev = original.rev;
    rev_dot = original.rev_dot;
    return *this;
}

BigNumber operator*(const BigNumber &a, const BigNumber &b) {
    unsigned sa = a.rev.size();
    unsigned sb = b.rev.size();

    unsigned sr = sa + sb;
    BigNumber r(sr, a.rev_dot + b.rev_dot);
    for (unsigned i = 0; i != sa; ++i) {
        for (unsigned j = 0; j != sb; ++j) {
            r.rev[i + j] += a.rev[i] * b.rev[j];
        }
    }

    for (unsigned i = 0; i != sr - 1; ++i) {
        r.rev[i + 1] += r.rev[i] / 10;
        r.rev[i] %= 10;
    }
    return r;
}

string BigNumber::toString() {
    unsigned s = rev.size();
    string number;
    number.reserve(s + 1);

    // 如果数字为 0 直接返回
    bool is_zero = true;
    for (unsigned i = 0; i != s; ++i) {
        if (rev[i] != 0) {
            is_zero = false;
            break;
        } 
    }

    if (is_zero) {
        return "0";
    }

    // 反转数字
    // reverse(rev.begin(), rev.end());
    
    vector<int> &num_vec = rev;

    // TODO: 构造字符串部分有待优化
    // FIXME: 小数点位置?

    for (unsigned i = 0; i != rev_dot; ++i) {
        number += static_cast<char>(num_vec[i] + static_cast<int>('0'));
    }
    number += '.';
    for (unsigned i = rev_dot; i != s; ++i) {
        number += static_cast<char>(num_vec[i] + static_cast<int>('0'));
    }
    // cout << number << endl;
    
    // 翻转数字字符串
    reverse(number.begin(), number.end());
    int dot = s - rev_dot;

    // 整数部分和小数部分不可能同时为 0
    int start = number.find_first_not_of("0");
    int end = number.find_last_not_of("0");
    string res;
    if (end == dot) {
        // 如果没有小数部分
        res = number.substr(start, dot - start);
    } else {
        res = number.substr(start, end - start + 1);
    }

    return res;
}

BigNumber pow(const BigNumber &base, unsigned exponent) {
    if (exponent == 0) {
        return BigNumber("1");
    }
    if (exponent == 1) {
        return base;
    } else {
        BigNumber temp = pow(base, exponent / 2);
        BigNumber res = temp * temp;
        if (exponent % 2 == 1) {
            return res * base;
        }
        return res;
    }
}

BigNumber::~BigNumber(){}