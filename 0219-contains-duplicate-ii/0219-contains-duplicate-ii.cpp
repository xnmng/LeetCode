class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        for (auto i = 0; i < nums.size(); ++i) {
            if (!s.insert(nums[i]).second) return true;
            if (i >= k) {
                s.erase(nums[i-k]);
            }
        }
        return false;
    }
};