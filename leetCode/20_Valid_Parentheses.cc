#include <stack>
#include <string>

using std::stack;
using std::string;

class Solution {
public:
    bool isValid(const string &s) {
        for (auto &c : s) {
            switch (c) {
                case ')':
                    if (match.empty() || match.top() != '(') {
                        return false;
                    } else {
                        match.pop();
                    }
                    break;
                case '}':
                    if (match.empty() || match.top() != '{') {
                        return false;
                    } else {
                        match.pop();
                    }
                    break;
                case ']':
                    if (match.empty() || match.top() != '[') {
                        return false;
                    } else {
                        match.pop();
                    }
                    break;
                default:
                    match.push(c);
            }
        }
        return match.empty();
    }

private:
    stack<char> match;
};