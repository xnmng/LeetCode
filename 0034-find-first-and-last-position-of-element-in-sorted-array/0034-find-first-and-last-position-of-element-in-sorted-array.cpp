class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans{-1, -1};
        if (nums.empty()) return ans;
        int left = 0; 
        int right = nums.size() - 1;
        int mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (target <= nums[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
            // cout << left << " " << mid << " " << right << "\n";
        }
        // definitely doesnt contain answer - early return
        // no point performing 2nd binary search
        if (nums[left] != target) return ans;
        ans[0] = left;
        left = 0;
        right = nums.size() - 1;
        // cout << "2nd binary search: \n";
        while (left < right) {
            mid = right - (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid;
            } else {
                right = mid-1;
            }
            // cout << left << " " << mid << " " << right << "\n";
        }
        // cout << left << "\n";
        // if (left+1 == arr.size()) ans[1] = left-1;
        ans[1] = left; // std::upper_bound implementation
        return ans;
    }
};
// [1]
// 1
// [5,7,7,7,8,10]
// 7
// [2,2]
// 2