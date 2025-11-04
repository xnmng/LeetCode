class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        unordered_map<int,int> mp;
        int n = nums.size();

        for (int i = 0; i < k; ++i) {
            ++mp[nums[i]];
        }
        ans.push_back(helper(mp, x));
        for (int i = k; i < n; ++i) {
            ++mp[nums[i]];
            --mp[nums[i - k]];
            ans.push_back(helper(mp, x));
        }
        return ans;
    }

    int helper(unordered_map<int,int>& mp, int x) {
        vector<pair<int,int>> v(mp.begin(), mp.end()); // freq, num
        // for (auto [k,val] : mp) {
            // v.emplace_back(k, val);
        // }
        sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second != b.second) {
                return a.second > b.second;
            }
            return a.first > b.first;
        });
        int ans = 0;
        for (int i = 0; i < min(x, (int)v.size()); ++i) {
            ans += v[i].first * v[i].second;
        }
        return ans;
    }
};