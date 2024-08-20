class Solution {
public:
    // can only split into 2 halves such that each half has distinct elements 
    // only when freq of each number in original arr is at most 2
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int,int> mp;
        for (auto i : nums) {
            if (mp[i] == 2) return false;
            ++mp[i];
        }
        return true;
    }
};