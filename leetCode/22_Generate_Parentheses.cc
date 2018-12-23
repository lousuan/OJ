#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        append("", n, 0);
        return result;
    }

private:
    void append(string prefix, int left, int right) {
        if (left == 0 && right == 0) {
            result.push_back(prefix);
            return;
        }

        if (left > 0) {
            append(prefix + "(", left - 1, right + 1);
        }
        if (right > 0) {
            append(prefix + ")", left, right - 1);
        }
        return;
    }
    vector<string> result;
};