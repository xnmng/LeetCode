// https://leetcode.com/problems/tallest-billboard/discuss/203181/JavaC++Python-DP-min(O(SN2)-O(3N2-*-N)
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        // suppose we have 2 heights a and b
        // (d, h) means we have a difference of d and the min. height is h := min(a, b);
        unordered_map<int,int> dp; 
        auto ans{0};
        dp[0] = 0;
        for (auto& i : rods) {
            unordered_map<int,int> temp(dp); // update a copy while iterating through state
            for (auto& [d, h] : dp) {
                // at each step, we can either extend the difference, or try to make it smaller
                temp[d + i] = max(temp[d + i], h); // extend using rod
                temp[abs(d - i)] = max(temp[abs(d - i)], h + min(d, i)); // make smaller using rod
            }
            swap(temp, dp);
        }
        return dp[0];
    }
};
// [96,112,101,100,104,93,106,99,114,81,94]