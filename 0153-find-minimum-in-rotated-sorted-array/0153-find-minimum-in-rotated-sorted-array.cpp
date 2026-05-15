class Solution {
public:
    int findMin(vector<int>& nums) {
        int localMin = nums[0];
        
        int left = 0;
        int right = nums.size() - 1;
        
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[left] < nums[right]) {
                localMin = min(localMin, nums[left]);
                break;
            }
            
            localMin = min(localMin, nums[mid]);

            if (nums[left] <= nums[mid]) {
            left = mid + 1;
           
            } else {
                right = mid - 1;
            }
        }
        
        return localMin;
        
    }
};