class Solution {
public:
    long long findScore(vector<int>& nums) {
        vector<pair<int,int>> v;
        v.reserve(nums.size());
        for (auto i = 0; i < nums.size(); ++i) {
            v.emplace_back(nums[i], i);
        }
        sort(v.begin(), v.end());
        unordered_set<int> s;
        long long ans{0};
        for (auto& [value, index] : v) {
            if (s.find(index) != s.end()) continue;
            ans += value;
            s.insert(index);
            s.insert(index+1);
            s.insert(index-1);
        }
        return ans;
    }
};