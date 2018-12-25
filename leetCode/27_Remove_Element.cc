#include <vector>

using std::vector;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        auto index = nums.begin();
        for (auto i = nums.begin(); i != nums.end(); ++i) {
            if (*i != val) {
                *index = *i;
                ++index;
                ++count;
            }
        }
        return count;
    }
};