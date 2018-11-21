#include <iostream>

using std::cout;
using std::endl;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) {
            return false;
        }
        int reversed_x = 0;
        while (x > reversed_x) {
            reversed_x = (reversed_x * 10) + (x % 10);
            x = x / 10;
        }
        return (x == reversed_x) || (x == reversed_x / 10);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    Solution solve;
    cout << solve.isPalindrome(123) << endl;
}
