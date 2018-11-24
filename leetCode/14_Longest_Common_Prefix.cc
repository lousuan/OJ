#include <iostream>
#include <vector>

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
        for (; prefix != strs[0][prefix]; ++prefix) {
            const int loop = strs.size();
            for (int i = 0; i != loop; ++i) {
                if (strs[0][prefix] != strs[i][prefix]) {
                    match = false;
                    break;
                }
            }
            if (!match) {
                break;
            }
        }
        if (prefix > 0) {
            return strs[0].substr(0, prefix);
        }
        return "";
    }
};