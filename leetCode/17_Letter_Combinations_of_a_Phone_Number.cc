#include <iostream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    vector<string> result;
    vector<string> letterCombinations(const string &digits) {
        combinate(digits, "", 0);
        return result;
    }

private:
    const static vector<string> dict;
    void combinate(const string &digits, const string &prefix,
                   const unsigned index) {
        if (index != digits.length() - 1) {
            for (auto const &i : dict[digits[index] - '2']) {
                combinate(digits, prefix + i, index + 1);
            }
        } else {
            for (auto const &i : dict[digits[index] - '2']) {
                result.push_back(prefix + i);
            }
        }
        return;
    };
};

const vector<string> Solution::dict = {"abc", "def",  "ghi", "jkl",
                                       "mno", "pqrs", "tuv", "wxyz"};

int main() {
    Solution s;
    s.letterCombinations("23");
}