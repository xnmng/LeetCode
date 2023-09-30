class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> v(60, 0);
        int ans = 0;
        for (auto i : time) {
            ans += v[(60 - (i % 60)) % 60];
            ++v[i % 60];
        }
        return ans;
    }
};