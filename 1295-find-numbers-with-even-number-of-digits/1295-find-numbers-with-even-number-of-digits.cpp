class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        bool isEven;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            isEven = true;
            while (nums[i] > 0) {
                isEven ^= true;
                nums[i] /= 10;
            }
            ans += isEven;
        }
        return ans;
    }
};