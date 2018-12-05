class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int middle1 = (nums1.size() + nums2.size() + 1) / 2, 
            middle2 = (nums1.size() + nums2.size()) / 2 + 1, 
            kth = 0, index1 = 0, index2 = 0;
        double median = 0;
        while (index1 + index2 < middle1) {
            if (nums1[index1] < nums2[index2])
                ++index1;
            else
                ++index2;
        }

        median = (nums1[index1] < nums2[index2]) ? nums1[index1++] : nums2[index2++];
        if (middle1 == middle2) {
            return median;
        } else {
            median += (nums1[index1] < nums2[index2]) ? nums1[index1++] : nums2[index2++];
        }
        
    }
};