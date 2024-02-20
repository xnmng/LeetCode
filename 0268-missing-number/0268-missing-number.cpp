class Solution {
public:
    // if all [0, n] numbers were in the range, the total sum would be (n * (n+1) / 2)
    // to find the missing number,
    // take the expected sum and subtract it with the total sum of the vector of nums
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = (n * (n+1) / 2);
        for (auto i : nums) ans -= i;
        return ans;
    }
};