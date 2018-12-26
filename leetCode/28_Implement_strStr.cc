#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::ostream;
using std::string;
using std::to_string;
using std::vector;

class Solution {
public:
    int strStr(const string &s, const string &pattern) const {
        if (pattern.size() == 0) return 0;
        if (s.size() < pattern.size()) return -1;
        unsigned current_matched_length = 0;
        vector<int> end_of_last_match = compute_matched_prefix(pattern);
        for (unsigned i = 0; i != s.size(); ++i) {
            while (current_matched_length != 0 &&
                   pattern[current_matched_length] != s[i]) {
                current_matched_length =
                    end_of_last_match[current_matched_length - 1] + 1;
            }
            if (pattern[current_matched_length] == s[i])
                ++current_matched_length;
            if (current_matched_length == pattern.size())
                return (i - current_matched_length + 1);
        }

        return -1;
    }

private:
    vector<int> compute_matched_prefix(const string &pattern) const {
        int length = pattern.size();
        vector<int> matched_prefix(length, -1);
        int current_matched_length = 0;
        for (int i = 1; i != length; ++i) {
            while (current_matched_length != 0 &&
                   pattern[current_matched_length] != pattern[i]) {
                current_matched_length =
                    // current_matched_length - 1 ==
                    // end_index_of_current_matched_prefix
                    matched_prefix[current_matched_length - 1] + 1;
            }
            if (pattern[current_matched_length] == pattern[i]) {
                ++current_matched_length;
            }
            matched_prefix[i] = current_matched_length - 1;
        }
        return matched_prefix;
    }
};

class Args {
public:
    string s;
    string pattern;
    Args(const string &s, const string &pattern) : s(s), pattern(pattern){};
    string ToString() const {
        return "s: \"" + s + "\", pattern : \"" + pattern + "\"";
    }
};
ostream &operator<<(ostream &os, const Args &args) {
    os << args.ToString();
    return os;
}

class TestCase {
public:
    Args args;
    int want;
    TestCase(Args args, int want) : args(args), want(want){};
    string ToString() const {
        return "Args: " + args.ToString() + ", want: " + to_string(want);
    }
};

ostream &operator<<(ostream &os, const TestCase &c) {
    os << c.ToString();
    return os;
}

bool test(const Solution &slover, const TestCase &c) {
    int result = slover.strStr(c.args.s, c.args.pattern);
    if (result != c.want) {
        cout << c << ", result: " << result << "." << endl;
    }
    return result == c.want;
}

int main() {
    std::ios::sync_with_stdio(false);
    Solution s;
    vector<TestCase> cases = {
        TestCase(Args("aabaaabaaac", "aabaaac"), 4),
        TestCase(Args("mississippi", "issip"), 4),
        TestCase(Args("baaaaaaabaababab", "aaaaa"), 1),
        TestCase(Args("aaab", "ab"), 2),
        TestCase(Args("aaab", "c"), -1),
    };
    bool passed = true;
    for (auto &c : cases) {
        if (!test(s, c)) {
            passed = false;
        }
    }

    cout << (passed ? "Test passed." : "Test failed.") << endl;
}