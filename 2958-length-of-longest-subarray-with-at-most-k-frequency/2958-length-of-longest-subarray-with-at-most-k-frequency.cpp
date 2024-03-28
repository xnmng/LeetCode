class Solution {
public:
    // TODO: second approach; same TC SC
    //
    // 2 pointers, find largest length, return it
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        int left = 0;
        int right = 0;
        unordered_map<int,int> mp;
        while (right < n) {
            ++mp[nums[right]];
            while (mp[nums[right]] > k) {
                --mp[nums[left]];
                ++left;
            }
            // cout << left << " " << right << "\n";
            ans = max(ans, right - left + 1);
            ++right;
        }
        return ans;
    }
    
    // dont actually need this to check, just check nums[right] 
    // (because of invaraint before loop - all freq <= k)
    // bool isValid(unordered_map<int,int>& mp, int k) {
    //     for (auto& [_,v] : mp) {
    //         if (v > k) return false;
    //     }
    //     return true;
    // }
};
// [1,4,4,3]
// 1