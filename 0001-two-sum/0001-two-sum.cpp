class Solution {
public:
    // either:
    // O(n^2) time, O(1) space (two pointers, keep moving left forward and check each possible right)
    // O(n) time, O(n) space (umap and find its complement)
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