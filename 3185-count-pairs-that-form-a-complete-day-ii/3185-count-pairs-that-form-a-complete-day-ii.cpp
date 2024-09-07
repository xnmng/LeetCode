class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long ans = 0;
        vector<int> v(24, 0);
        for (int i : hours) {
            if (i % 24 == 0) {
                ans += v[0];
                ++v[0];
            } 
            else {
                ans += v[24 - (i % 24)];
                ++v[i % 24];
            }
        }
        return ans;
    }
};