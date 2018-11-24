#include <iostream>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Solution {
public:
    int romanToInt(const string &s) {
        int sum = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (map[s[i]] < map[s[i + 1]]) {
                sum -= map[s[i]];
            } else {
                sum += map[s[i]];
            }
        }
        return sum;
    }

private:
    static unordered_map<char, int> map;
};

unordered_map<char, int> Solution::map = {{'I', 1},   {'V', 5},   {'X', 10},
                                          {'L', 50},  {'C', 100}, {'D', 500},
                                          {'M', 1000}};