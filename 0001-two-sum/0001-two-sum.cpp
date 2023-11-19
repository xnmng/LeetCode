class Solution {
public:
    // either:
    // O(n^2) time, O(1) space
    // O(n) time, O(n) space
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp; // <num, index>
        int n = nums.size();
        vector<int> ans;
        for (auto i = 0; i < n; ++i) {
            if (mp.find(target - nums[i]) == mp.end()) {
                mp[nums[i]] = i; 
            } else {
                ans = {i, mp[target - nums[i]]};
                break;
            }
        }
        return ans;
    }
};