class Solution {
public:
    // constraints very small; brute force recursion
    // https://leetcode.com/problems/different-ways-to-add-parentheses/discuss/66331/C++-4ms-Recursive-and-DP-solution-with-brief-explanation
    //
    // alternatively, do DP for repeated states (e.g. 2+2+2+2)
    // DP solution (small changes from recursive solution)
    vector<int> diffWaysToCompute(string expression, 
                                  unordered_map<string, vector<int>> dp = unordered_map<string, vector<int>>()) {
        if (dp.find(expression) == dp.end()) {
            vector<int> ans; // duplicates are OK!
            int n = expression.size();
            for (int i = 0; i < n; ++i) {
                if (expression[i] - '0' < 0 ||
                   expression[i] - '0' > 9) {
                    vector<int> left = diffWaysToCompute(expression.substr(0, i), dp);
                    vector<int> right = diffWaysToCompute(expression.substr(i+1), dp);
                    for (int x : left) {
                        for (int y : right) {
                            if (expression[i] == '+') {
                                ans.emplace_back(x + y);
                            }
                            else if (expression[i] == '-') {
                                ans.emplace_back(x - y);
                            }
                            else if (expression[i] == '*') {
                                ans.emplace_back(x * y);
                            }
                        }
                    }
                }
            }

            // no operators
            if (ans.empty()) {
                ans.emplace_back(stoi(expression));
            }
            dp[expression] = ans;
        }
        return dp[expression];
    }
    
    
//     // recursive solution (good enough to pass) 
//     // O(n * 2^n) time, O(2^n) space
//     vector<int> diffWaysToCompute(string expression) {
//         vector<int> ans; // duplicates are OK!
//         int n = expression.size();
//         for (int i = 0; i < n; ++i) {
//             if (expression[i] - '0' < 0 ||
//                expression[i] - '0' > 9) {
//                 vector<int> left = diffWaysToCompute(expression.substr(0, i));
//                 vector<int> right = diffWaysToCompute(expression.substr(i+1));
//                 for (int x : left) {
//                     for (int y : right) {
//                         if (expression[i] == '+') {
//                             ans.emplace_back(x + y);
//                         }
//                         else if (expression[i] == '-') {
//                             ans.emplace_back(x - y);
//                         }
//                         else if (expression[i] == '*') {
//                             ans.emplace_back(x * y);
//                         }
//                     }
//                 }
//             }
//         }
        
//         // no operators
//         if (ans.empty()) {
//             ans.emplace_back(stoi(expression));
//         }
//         return ans;
//     }
};