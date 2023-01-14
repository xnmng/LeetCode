class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        for (auto i : tasks) ++mp[i];
        auto ans{0};
        for (auto &[k,v] : mp) {
            if (v == 1) return -1;
            ans += v/3;
            if (v % 3 != 0) ++ans;
        }
        return ans;
    }
};