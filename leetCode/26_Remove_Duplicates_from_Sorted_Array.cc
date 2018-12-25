#include <vector>

using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.begin() == nums.end()) {
            return 0;
        }
        int count = 1;
        auto slow = nums.begin();

        for (auto fast = nums.begin() + 1; fast != nums.end(); ++fast) {
            if (*fast != *slow) {
                ++slow;
                *slow = *fast;
                ++count;
            }
        }

        // if (nums.size() == 0) {
        //     return 0;
        // }
        // int count = 0;
        // for (int index = 1; index != nums.size(); ++index) {
        //     if (nums[count] != nums[index]) {
        //         ++count;
        //         nums[count] = nums[index];
        //     }
        // }
        // return ++count;
    }
};