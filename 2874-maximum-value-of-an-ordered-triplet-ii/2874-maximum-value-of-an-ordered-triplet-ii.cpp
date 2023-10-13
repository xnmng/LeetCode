class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        long long maxVal = 0;
        long long maxDiff = 0;
        for (auto i : nums) {
            ans = max(ans, maxDiff * i);
            maxVal = max(maxVal, 1ll * i);
            maxDiff = max(maxDiff, maxVal - i);
        }        
        return ans;
    }
};