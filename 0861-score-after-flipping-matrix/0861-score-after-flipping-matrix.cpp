class Solution {
public:
    // greedy
    //
    // first row should always be 1 (e.g. 1000 > 0111)
    // columns if got more 0 than 1, flip
    //
    // (note: for implementation, dont actually need to perform the flips - O(M) space)
    //
    // if perform the flips, same TC (traverse mn twice), but O(1) space
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<bool> v(m, false);
        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 0) v[i] = true;
        }
        
        int ans = 0;
        int count = 0;
        // iterate across each column
        for (int i = 0; i < n; ++i) {
            count = 0;
            for (int j = 0; j < m; ++j) { // index of v
                if ((v[j] && grid[j][i] == 0) 
                    || (!v[j] && grid[j][i] == 1)) ++count;
            }
            if (count * 2 < m) count = m - count;
            // cout << i << " " << count << "\n";
            // cout << count * pow(2, n - i - 1) << " " << pow(2, n - i - 1) << "\n\n";
            ans += count * pow(2, n - i - 1);
        }
        return ans;
        // // form answer and return
        // int ans = 0;
        // int cur;
        // for (auto& i : grid) {
        //     cur = 0;
        //     for (auto j : i) {
        //         cur *= 2;
        //         cur += j;
        //     }
        //     ans += cur;
        // }
    }
};