#include <cassert>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution {
public:
    bool isMatch(const string &s, const string &p) {
        int sl = s.length();
        int pl = p.length();
        match.resize(sl + 1, vector<bool>(pl + 1, false));
        match[0][0] = true;
        for (int i = 0; i <= sl; ++i) {
            // match[0][j] == false (j > 0) pattern 不为空时，不能匹配空字符串
            for (int j = 1; j <= pl; ++j) {
                if (p[j - 1] == '*') {
                    // match[i][j] = match[i][j - 2] 相当于忽略'*'和 p[j - 2]
                    // match[i][j] = (s[i - 1] == p[j - 2] || p[j - 2] == '.')
                    // && match[i - 1][j] 至少重复一次
                    match[i][j] =
                        match[i][j - 2] ||
                        (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') &&
                         match[i - 1][j]);
                } else {
                    match[i][j] = (i > 0 && match[i - 1][j - 1] &&
                                   (s[i - 1] == p[j - 1] || p[j - 1] == '.'));
                }
            }
        }
        return match[sl][pl];
    }

private:
    // match[i][j] 为真当且仅当 s[0...i-1]==p[0....j-1]
    vector<vector<bool>> match;
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() - 1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i + 1];
            switch (nextChar) {
                case '\"':
                    result.push_back('\"');
                    break;
                case '/':
                    result.push_back('/');
                    break;
                case '\\':
                    result.push_back('\\');
                    break;
                case 'b':
                    result.push_back('\b');
                    break;
                case 'f':
                    result.push_back('\f');
                    break;
                case 'r':
                    result.push_back('\r');
                    break;
                case 'n':
                    result.push_back('\n');
                    break;
                case 't':
                    result.push_back('\t');
                    break;
                default:
                    break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}

string boolToString(bool input) { return input ? "True" : "False"; }

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        string p = stringToString(line);

        bool ret = Solution().isMatch(s, p);

        string out = boolToString(ret);
        cout << (s[2] == p[4]) << " " << (s[2] == p[4] || p[4] == '.') << endl;
        cout << out << endl;
    }
    return 0;
}