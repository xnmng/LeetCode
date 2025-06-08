class Solution {
public:
    // O(n) time, O(1) space solution
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        ans.reserve(n);
        int cur = 1;

        // generate exactly n numbers
        for (int i = 0; i < n; ++i) {
            ans.emplace_back(cur);

            // generate next number in the sequence
            if (cur * 10 <= n) cur *= 10;
            else {
                while (cur % 10 == 9 || cur >= n) cur /= 10;
                ++cur;
            }
        }

        return ans;
    }
};

// // O(n) time, O(logn) space solution
// class Solution {
// public:
//     // https://leetcode.com/problems/lexicographical-numbers/discuss/86288/7-lines-simple-C++-recursive-solution
//     vector<int> lexicalOrder(int n) {
//         vector<int> ans;
//         ans.reserve(n);
//         dfs(1, n, ans);
//         return ans;
//     }
    
//     void dfs(int cur, int n, vector<int>& ans) {
//         if (cur > n) return;
//         ans.emplace_back(cur);
//         dfs(cur * 10, n, ans);
//         if (cur % 10 != 9) dfs(cur + 1, n, ans);
//     }
// };