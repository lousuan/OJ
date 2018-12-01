#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using std::cout;
using std::endl;
using std::min;
using std::numeric_limits;
using std::string;
using std::vector;

class Solution {
public:
    string longestCommonPrefix(const vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        if (strs.size() == 1) {
            return strs[0];
        }
        int prefix = 0;
        bool match = true;
        unsigned min_length = numeric_limits<unsigned>::max();
        const int num_of_string = strs.size();
        for (const auto& s : strs) {
            min_length = min(min_length, (unsigned)s.length());
        }

        cout << min_length << endl;

        for (; prefix != min_length; ++prefix) {
            for (int i = 1; i != num_of_string; ++i) {
                if (strs[0][prefix] != strs[i][prefix]) {
                    match = false;
                    --prefix;
                    break;
                }
            }
            if (!match) {
                break;
            }
        }

        if (match) {
            --prefix;
        }

        cout << prefix << endl;

        if (prefix >= 0) {
            return strs[0].substr(0, prefix + 1);
        }
        return "";
    }
};

int main() {
    Solution s;
    vector<string> strs = {"flaaa", "fla", "fl"};
    cout << s.longestCommonPrefix(strs);
}