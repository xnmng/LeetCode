// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/discuss/4109932/Lonely-Element
class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for (auto i : nums) {
            ++mp[i];
        }
        int ans = 0;
        for (auto& [k,v] : mp) {
            // cout << k << " " << v << "\n";
            if (v == 1) return -1;
            ans += v/3 + (v % 3 > 0 ? 1 : 0);
        }
        return ans;
    }
};

// [14,12,14,14,12,14,14,12,12,12,12,14,14,12,14,14,14,12,12]
// [19,19,19,19,19,19,19,19,19,19,19,19,19]