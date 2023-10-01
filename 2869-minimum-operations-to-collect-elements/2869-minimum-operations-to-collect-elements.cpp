class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> s;
        int ans = 0;
        while (!nums.empty() && s.size() < k) {
            if (nums.back() <= k) {
                s.insert(nums.back());
            }
            nums.pop_back();
            ++ans;
        }
        return ans;
    }
};