class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        // we are binary searching over the range of pair values
        int left = 0;
        int right = nums.back() - nums.front();
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // count number of pairs with abs diff <= mid
            int count = helper(nums, mid);
            
            if (count < k) left = mid + 1;
            else right = mid;
        }
        return left;
    }
    
    // count number of pairs with abs diff <= mid
    int helper(vector<int>& nums, int mid) {
        int count = 0;
        int n = nums.size();
        int left = 0;
        int right = 0;
        // fixing right index, 
        // how many elements can we pick to make a pair diff <= mid?
        while (right < n) {
            while (nums[right] - nums[left] > mid) {
                ++left;
            }
            count += right - left;
            ++right;
        }
        return count;
    }
};