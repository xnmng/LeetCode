class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        auto cur{0};
        auto ans{0};
        for (auto& i : gain) {
            cur += i;
            ans = max(ans, cur);
        }
        return ans;
    }
};