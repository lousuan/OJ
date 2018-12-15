#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::sort;
using std::vector;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        result_size = 4;
        result.resize(result_size, 0);
        kSum(nums.begin(), nums.end() - 1, target, result_size);
        return results;
    }

private:
    int result_size = 0;
    vector<int> result;
    vector<vector<int>> results;
    void kSum(vector<int>::iterator left, vector<int>::iterator right,
              int target, int k) {
        if ((right - left + 1) < k) {
            return;
        }
        if (k > 2) {
            for (auto i = left; i <= right - k + 1; ++i) {
                *(result.end() - k) = *i;
                kSum(i + 1, right, target - *i, k - 1);
                while (i < right && *(i + 1) == *i) ++i;
            }
        } else {
            while (left < right) {
                int sum = *left + *right;
                if (sum > target) {
                    --right;
                } else if (sum < target) {
                    ++left;
                } else {
                    // 找到结果
                    *(result.end() - 2) = *left;
                    *(result.end() - 1) = *right;
                    results.push_back(result);
                    while (left < right && *left == *(result.end() - 2)) ++left;
                    // while (left < right && *right == *(result.end() - 1))
                    // --right;
                }
            }
        }
    }
};

int main() {
    Solution s;
    // vector<int> test = {1, 2, 3, 4, 5, 6, 7};
    // int target = 16;
    vector<int> test = {-2, -1, 0, 0, 1, 2};
    // vector<int> test = {1, 2, 3, 4};
    int target = 0;
    auto results = s.fourSum(test, target);

    for (const auto& result : results) {
        for (const auto& n : result) {
            cout << n << " ";
        }
        cout << endl;
    }
}