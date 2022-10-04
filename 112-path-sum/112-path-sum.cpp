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
    bool dfs(TreeNode* root, int targetSum, int curSum) {
        if (!root) return false;
        if (!root->left && !root->right) return targetSum == curSum + root->val;
        auto l{dfs(root->left, targetSum, curSum + root->val)};
        auto r{dfs(root->right, targetSum, curSum + root->val)};
        return l || r;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        return dfs(root, targetSum, 0);
    }
};

// empty tree -> no path!
// []
// 0
// [1,2]
// 1