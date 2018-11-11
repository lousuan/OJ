#include <iostream>
#include <limits>

using std::numeric_limits;
using std::string;

class Solution {
public:
    int myAtoi(string str) {
        result = 0;
        positive = true;
        for (int i = 0; i < str.size();) {
            i = str.find_first_not_of(' ');
            if (str[i] == '-' || str[i] == '+')
                positive = (str[i++] == '-') ? false : true;
            while ('0' <= str[i] && str[i] <= '9') {
                int temp = result * 10 + (str[i++] - '0');
                if (temp / 10 != result) {
                    return (positive ? numeric_limits<int>::max()
                                     : numeric_limits<int>::min());
                }
                result = temp;
            }
            return (positive ? result : -result);
        }
        return 0;  // 长度为 0 的字符串
    }

private:
    int result;
    bool positive;
};