class Solution {
public:
    // sort, then partition, keep track of min in cur partition, 
    // if needed, increment no. of partitions needed
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int prev = INT_MIN / 2;
        int ans = 0;
        for (int i : nums) {
            if (i - prev > k) {
                ++ans;
                prev = i;
            }
        }
        return ans;
    }
};