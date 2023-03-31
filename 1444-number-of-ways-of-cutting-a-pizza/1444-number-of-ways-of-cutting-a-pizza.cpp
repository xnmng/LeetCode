class Solution {
public:
    int ways(vector<string>& pizza, int slices) {
        auto m{static_cast<int>(pizza.size())};
        auto n{static_cast<int>(pizza[0].size())};
        auto modulo{static_cast<long>(1e9 + 7)};
        
        vector<vector<long>> prev(m, vector<long>(n, 0));
        vector<vector<long>> dp;
        
        // apples[i][j] := number of apples starting from pizza[i][j] to bottom right
        vector<vector<int>> apples(m+1, vector<int>(n+1));
        for (auto i = m-1; i >= 0; --i) {
            for (auto j = n-1; j >= 0; --j) {
                apples[i][j] = (pizza[i][j] == 'A') 
                    + apples[i+1][j] + apples[i][j+1] - apples[i+1][j+1];
                
                if (apples[i][j] > 0) prev[i][j] = 1;
            }
        }
        // for (auto i : prev) {
        //     for (auto j : i) {
        //         cout << j << " ";
        //     }
        //     cout << "\n";
        // }
        
        for (auto i = 1; i < slices; ++i) {
            dp = vector<vector<long>>(m, vector<long>(n));
            for (auto j = 0; j < m; ++j) {
                for (auto k = 0; k < n; ++k) {
                    for (auto row = j+1; row < m; ++row) {
                        if (apples[j][k] - apples[row][k] > 0) {
                            dp[j][k] += prev[row][k];
                            dp[j][k] %= modulo;
                        }
                    }
                    for (auto col = k+1; col < n; ++col) {
                        if (apples[j][k] - apples[j][col] > 0) {
                            dp[j][k] += prev[j][col];
                            dp[j][k] %= modulo;
                        }
                    }
                }
            }
            // for (auto i : dp) {
            //     for (auto j : i) {
            //         cout << j << " ";
            //     }
            //     cout << "\n";
            // }
            swap(prev, dp);
        }
        return prev[0][0];
    }
};

// class Solution {
// public:
//     int ways(vector<string>& pizza, int slices) {
//         // cout << slices << " " << pizza.size() << " " << pizza[0].size() << "\n";
//         auto m{static_cast<int>(pizza.size())};
//         auto n{static_cast<int>(pizza[0].size())};
//         auto modulo{static_cast<long>(1e9 + 7)};
        
//         // dp[remain][r][c] := number of ways to cut pizza starting from row r to end 
//         //                      and col c to end with remain number of cuts
//         vector<vector<vector<long>>> 
//             dp(slices, vector<vector<long>>(pizza.size(), vector<long>(pizza[0].size())));
        
//         // apples[i][j] := number of apples starting from pizza[i][j] to bottom right
//         vector<vector<int>> apples(pizza.size()+1, vector<int>(pizza[0].size()+1));
//         for (auto i = m-1; i >= 0; --i) {
//             for (auto j = n-1; j >= 0; --j) {
//                 if (pizza[i][j] == 'A') ++apples[i][j];
//                 if (i+1 < m) apples[i][j] += apples[i+1][j];
//                 if (j+1 < n) apples[i][j] += apples[i][j+1];
//                 if (i+1 < m && j+1 < n) apples[i][j] -= apples[i+1][j+1];
                
//                 if (apples[i][j] > 0) dp[0][i][j] = 1;
//             }
//         }
//         // for (auto i : apples) {
//         //     for (auto j : i) {
//         //         cout << j << " ";
//         //     }
//         //     cout << "\n";
//         // }
            
//         // dp[remain][row][col] == dp[i][j][k]
//         for (auto i = 1; i < slices; ++i) {
//             for (auto j = 0; j < pizza.size(); ++j) {
//                 for (auto k = 0; k < pizza[0].size(); ++k) {
//                     // horizontal cut (j ... row-1, row ... row_end)
//                     for (auto row = j+1; row < pizza.size(); ++row) {
//                         if (apples[j][k] - apples[row][k] > 0) {
//                             dp[i][j][k] += dp[i-1][row][k];
//                             dp[i][j][k] %= modulo;
//                         }
//                     }
//                     // vertical cut (k ... col-1, col ... col_end)
//                     for (auto col = k+1; col < pizza[0].size(); ++col) {
//                         if (apples[j][k] - apples[j][col] > 0) {
//                             dp[i][j][k] += dp[i-1][j][col];
//                             dp[i][j][k] %= modulo;
//                         }
//                     }
//                 }
//             }
//         }
//         // for (auto i : dp) {
//         //     for (auto j : i) {
//         //         for (auto k : j) {
//         //             cout << k << " ";
//         //         }
//         //         cout << "\n";
//         //     }
//         //     cout << "\n";
//         // }
//         return dp[slices-1][0][0];
//     }
// };
