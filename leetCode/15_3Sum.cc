#include <algorithm>
#include <iostream>
#include <vector>

using std::sort;
using std::vector;

using std::cout;
using std::endl;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (auto i = nums.begin(); i != nums.end(); ++i) {
            int target = -(*i);
            auto left = i + 1;
            auto right = nums.end() - 1;

            while (left < right) {
                int sum = *left + *right;
                if (sum < target) {
                    ++left;
                } else if (sum > target) {
                    --right;
                } else {
                    vector<int> tuple(3, 0);
                    tuple[0] = *i;
                    tuple[1] = *left;
                    tuple[2] = *right;
                    result.push_back(tuple);
                    while (left < right && *left == tuple[1]) ++left;
                    while (left < right && *right == tuple[2]) --right;
                }
            }
            while (i + 1 != (nums.end()) && *(i + 1) == *i) ++i;
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> test = {0};
    auto result = s.threeSum(test);

    for (auto& t : result) {
        cout << t[0] << " " << t[1] << " " << t[2] << endl;
    }
}