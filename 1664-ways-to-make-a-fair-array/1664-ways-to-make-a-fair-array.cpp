class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        // store {evenSum, oddSum}
        vector<pair<int,int>> leftSum{{0, 0}};
        vector<pair<int,int>> rightSum(n);
        int left = 0;
        int right = 0;
        for (auto i = 0; i < nums.size(); ++i) {
            i % 2 == 0 ? left += nums[i] : right += nums[i];
            leftSum.emplace_back(left, right);
        }
        left = 0;
        right = 0;
        // if we remove element, parity of everything changes
        // oddSum becomes evenSum, evenSum becomes oddSum
        for (auto i = n-1; i >= 0; --i) {
            i % 2 == 0 ? left += nums[i] : right += nums[i];
            if (i-1 >= 0) rightSum[i-1] = {right, left};
        }
        
        // for (auto i = 0; i < n; ++i) {
        //     cout << i << " " << leftSum[i].first << " " << leftSum[i].second << "\n";
        // }
        // for (auto i = 0; i < n; ++i) {
        //     cout << i << " " << rightSum[i].first << " " << rightSum[i].second << "\n";
        // }
        
        // if we remove index i, 
        // take value to be (leftSum[i].first + right[i].first) 
        // and (leftSum[i].second + rightSum[i].second)
        for (auto i = 0; i < n; ++i) {
            // cout << "remove element at index " << i << "\n";
            // cout << "evensum=" << leftSum[i].first + rightSum[i].first 
            //     << " oddsum=" << leftSum[i].second + rightSum[i].second << "\n";
            if (leftSum[i].first + rightSum[i].first 
                - leftSum[i].second - rightSum[i].second == 0) ++ans;
        }
        return ans;
    }
};
