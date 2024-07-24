class Solution {
public:
    // https://leetcode.com/problems/sort-the-jumbled-numbers/solution/
    // 
    // map the number, then sort, then construct ans
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>> v;
        v.reserve(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            int cur = 0;
            int temp = nums[i];
            int offset = 1;
            // edge case, when temp IS 0
            if (temp == 0) {
                v.emplace_back(mapping[0], i);
                continue;
            }
            while (temp != 0) {
                cur += offset * mapping[temp % 10];
                temp /= 10;
                offset *= 10;
            }
            v.emplace_back(cur, i); // preserve relative mapping; store index, not nums[i]
        }
        sort(v.begin(), v.end());
        vector<int> ans;
        ans.reserve(nums.size());
        for (auto& [_, index] : v) {
            ans.emplace_back(nums[index]);
        }
        return ans;
    }
};
// [9,8,7,6,5,4,3,2,1,0]
// [0,1,2,3,4,5,6,7,8,9]