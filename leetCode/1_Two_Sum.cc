#include <iostream>
#include <vector>
#include <unordered_map>

using std::unordered_map;
using std::vector;
using std::cout;

class Solution_1 {
public:
    vector<int> twoSum(const vector<int>& nums, const int target) {
        for (int i = 0; i != nums.size(); ++i) {
            for (auto j = i + 1; j != nums.size(); ++j) {
                if (nums[j] == target - nums[i])
                    return {i, j};
            }
        }
    }
};

class Solution_2 {
public:
    vector<int> twoSum(const vector<int>& nums, const int target) {
        unordered_map<int, int> hashmap;
        for (int i = 0; i != nums.size(); ++i) {
            if (hashmap.find(target - nums[i]) != hashmap.end())
                return {i, (target - hashmap[nums[i]])->second};
            hashmap[nums[i]] = i;
        }
    }
};

class Solution_2_1 {
public:
    vector<int> twoSum(const vector<int>& nums, const int target) {
    unordered_map<int, int> imap;
    
        for (int i = 0;; ++i) {
            auto it = imap.find(target - nums[i]);        
            if (it != imap.end()) 
                return vector<int> {i, it->second};
            imap[nums[i]] = i;
        }
    }
}

int main() {
    Solution s;
    vector<int> test ={3, 2, 4};
	vector<int> &t = test; 
    vector<int> a = s.twoSum(t, 6);

    for (auto i : a)
        cout << i;
    
	return 0;
}
