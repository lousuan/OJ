#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using std::abs;
using std::cout;
using std::endl;
using std::min;
using std::numeric_limits;
using std::sort;
using std::vector;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int min_diff = numeric_limits<int>::max();
        for (auto i = nums.begin(); i != nums.end() - 2; ++i) {
            int new_target = target - (*i);
            auto left = i + 1;
            auto right = nums.end() - 1;

            while (left < right) {
                int sum = *left + *right;
                min_diff = abs(sum - new_target) < abs(min_diff)
                               ? sum - new_target
                               : min_diff;
                if (sum < new_target) {
                    ++left;
                } else if (sum > new_target) {
                    --right;
                } else {
                    return target;
                }
            }
            // while (left < right && *left == *(left + 1)) ++left;
            // while (left < right && *right == *(right + 1)) --right;
        }
        return target + min_diff;
    }
};

int main() {
    Solution s;
    vector<int> testcase = {0, 1, 2};
    cout << s.threeSumClosest(testcase, 3) << endl;
}