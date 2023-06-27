class Solution {
private:
    int dfs(int i, unordered_set<int>& s) {
        if (s.find(i) == s.end()) return 0;
        s.erase(i);
        return 1 + dfs(i+1, s) + dfs(i-1, s);
    }
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        auto ans{0};
        for (auto& i : nums) {
            if (s.find(i) == s.end()) continue;
            ans = max(ans, dfs(i, s));
        }
        return ans;
    }
};