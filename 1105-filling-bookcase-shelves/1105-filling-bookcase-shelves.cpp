class Solution {
public:
    // dp shelf by shelf
    // at each step (i), we try to put as many books on this shelf as possible
    // i.e. at index i, we try to put i-1, i-2, ... on this shelf
    // then store max height at this index
    // 
    // O(nw) time, O(n) space
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        // dp[i] := minimum height of shelf containing up to and incl books[i]
        // +1 to cover edge case
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        
        for (int i = 0; i < n; ++i) {
            dp[i+1] = dp[i] + books[i][1];
            int curWidth = 0;
            int curHeight = 0;
            for (int j = i; j >= 0; --j) {
                curWidth += books[j][0];
                if (curWidth > shelfWidth) break;
                curHeight = max(curHeight, books[j][1]);
                dp[i+1] = min(dp[i+1], dp[j] + curHeight);
            }
        }
        return dp.back();
    }
};