// TODO: learn and read improved solutions
class Solution {
public:
    // brute force the subset, then check that it is non-beautiful
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int,int> s;
        int ans = 0;
        dfs(nums, k, s, ans, 0);
        return ans;
    }
    
    void dfs(vector<int>& nums, int k, unordered_map<int,int>& s, int& ans, int index) {
        if (index == nums.size()) return;
        // cout << nums.size() << " " << index << "\n";
        if (s[nums[index] - k] == 0
            && s[nums[index] + k] == 0) {
            ++s[nums[index]];
            // we are adding an element, definitely is unique 
            // (in terms of index chosen; question definiton)
            ++ans; 
            dfs(nums, k, s, ans, index + 1);
            --s[nums[index]];
        }
        dfs(nums, k, s, ans, index + 1);
    }
};
// [1,1,2,3]
// 1