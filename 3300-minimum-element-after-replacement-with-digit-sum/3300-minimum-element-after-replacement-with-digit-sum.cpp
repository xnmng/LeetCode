class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        int count;
        for (int i : nums) {
            count = 0;
            while (i > 0) {
                count += i % 10;
                i /= 10;
            }
            ans = min(ans, count);
        }
        return ans;
    }
};