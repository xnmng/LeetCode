class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        auto ans{0};
        unordered_map<int,int> mp;
        for (auto& i : arr) {
            if (mp.find(i - difference) == mp.end()) mp[i] = 1;
            else mp[i] = 1 + mp[i - difference];
            ans = max(ans, mp[i]);
        }
        return ans;
    }
};