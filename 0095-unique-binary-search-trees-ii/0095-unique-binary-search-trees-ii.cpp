/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector<TreeNode*> dfs(int left, int right, vector<vector<vector<TreeNode*>>> dp) {
        if (left > right) return {nullptr};
        if (dp[left][right].empty()) {
            if (left == right) {
                dp[left][right] = {new TreeNode(left)};
            } else {
                for (auto i = left; i <= right; ++i) {
                    // let i be the root of BST
                    // left subtree contains [left, i-1]
                    // right subtree [i+1, right]
                    auto leftBST = dfs(left, i-1, dp);
                    auto rightBST = dfs(i+1, right, dp);
                    // apply cartesian product
                    for (auto x : leftBST) {
                        for (auto y : rightBST) {
                            dp[left][right].emplace_back(new TreeNode(i, x, y));
                        }
                    }
                }
            }
        }
        return dp[left][right];
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<vector<TreeNode*>>> dp(n+1, 
                                             vector<vector<TreeNode*>>(n+1, 
                                                                       vector<TreeNode*>()));
        return dfs(1, n, dp);
    }
};