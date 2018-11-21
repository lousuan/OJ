#include <algorithm>
#include <vector>

using std::max;
using std::min;
using std::vector;

class Solution {
public:
    int maxArea(const vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;
        while (left < right) {
            max_area = max(max_area,
                           (right - left) * min(height[left], height[right]));

            if (height[left] > height[right]) {
                --right;
            } else {
                ++left;
            }
        }
        return max_area;
    }
};

// 首先考虑最左和最右，两头不断向中间移动，每次都移动两头较矮的一头，以尽可能提高容量的下限。