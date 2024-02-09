// https://leetcode.com/problems/largest-divisible-subset/discuss/1578991/C++-4-Simple-Solutions-w-Detailed-Explanation-or-Optimizations-from-Brute-Force-to-DP
class Solution {
public:
    // i dont think sorting is necessary for DP? just check if either condition is true
    // EDIT: WRONG! need to sort!
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        
        // sorting is necessary (try out without sorting and with test case below; dk how to explain why)
        sort(nums.begin(), nums.end());
        
        // dp[i] := largest divisible subset from [nums[0],...,nums[i]] and including nums[i]
        // trivially, any nums[i] is >= 1 because we can use nums[i] alone as a subset
        vector<int> dp(n, 1);
        // prev[i] contains the index of the previous number in the subset, 
        // or -1 if this is the last element in the subset
        vector<int> prev(n, -1);
        // cur contains the starting index which we can use to build the ans
        int cur = 0;

        // initialize dp and prev then use prev and cur to construct ans subset
        for (int i = 0; i < n; ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                        if (dp[i] > dp[cur]) cur = i;
                    }
                }
            }
        }

        // for (auto i : nums) cout << i << " ";
        // cout << "\n";
        // for (auto i : dp) cout << i << " ";
        // cout << "\n";
        // for (auto i : prev) cout << i << " ";
        
        // build the ans and return
        vector<int> ans;
        while (cur != -1) {
            ans.emplace_back(nums[cur]);
            cur = prev[cur];
        }
        return ans;
    }
};
// [5,9,18,54,108,540,90,180,360,720]