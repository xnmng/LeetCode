class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        unordered_map<int,int> mp;
        int n = nums.size();
        int left = 0;
        int right = 0;
        int ans = 0;
        // make it cleaner; each step either add a right element or count and update left!
        while (right <= n) {
            if (mp.size() == s.size() && left <= right) {
                // number of complete subarrays starting at left and ending at right
                // +1 because prev iteration added right once
                // right is pointing to the NEXT element to be processed!!!
                ans += n - right + 1;
                // cout << left << " " << right << " " << n << " " << n - right + 1 << "\n";
                --mp[nums[left]];
                if (mp[nums[left]] == 0) mp.erase(nums[left]);
                ++left;
            }
            else {
                if (right == n) break;
                ++mp[nums[right]];
                ++right;
            }
        }
        return ans;
    }
};
// [1917,1917,608,608,1313,751,558,1561,608]