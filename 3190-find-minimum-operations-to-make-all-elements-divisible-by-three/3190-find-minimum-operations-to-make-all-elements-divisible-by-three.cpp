class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for (int i : nums) {
            ans += (i % 3 != 0);
        }
        return ans;
    }
};