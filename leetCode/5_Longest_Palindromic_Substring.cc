#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        if (size < 2) return s;
        for (int i = 0; i != size - 1; ++i) {
            tryToExtend(s, i, i);
            tryToExtend(s, i, i + 1);
        }
        return s.substr(start, max_length);
    }

private:
    int max_length = 0;
    int start = 0;

    void tryToExtend(const string &s, int left, int right) {
        while (left >= 0 && right != s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        if (max_length < right - left - 1) {
            start = left + 1;
            max_length = right - left - 1;
        }
    }
};

int main() {
    Solution solve;
    cout << solve.longestPalindrome("aba") << endl;

    return 0;
}