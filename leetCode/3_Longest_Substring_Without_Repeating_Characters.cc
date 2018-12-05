class Solution_1{
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        int max_length = 0;
        set<char> set;
        for (int i = 0, j = 0; i != size && j != size; ) {
            if (set.find(s[j]) == set.end()) {
                set.insert(s[j]);
                ++j;
                max_length = max_length < j - i ? j - i : max_length;
            } else {
                set.erase(s[i]);
                ++i;
            }
        }
        return max_length;
    }
};

class Solution_2{
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        int max_length = 0;
        unordered_map<char, int> hashmap;
        for (int i = 0, j = 0; i != size && j != size; ) {
            if (hashmap.find(s[j]) ！= hashmap.end()) {
                i = hashmap[s[j]] < i ? i : hashmap[s[j]] + 1; 
            } 
            max_length = max_length < (j - i + 1) ? (j - i + 1) : max_length;
            hashmap[s[j]] = j;           
        }
        return max_length;
    }
};

class Solution_2_1{
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        int max_length = 0;
        unordered_map<char, int> hashmap;
        for (int i = 0, j = 0; j != size; ++j) {
            if (hashmap.find(s[j]) != hashmap.end()) {
                i = hashmap[s[j]] < i ? i : hashmap[s[j]]; 
            } 
            max_length = max_length < (j - i + 1) ? (j - i + 1) : max_length;
            hashmap[s[j]] = j + 1;           
        }
        return max_length;
    }
};