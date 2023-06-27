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
    void dfs(TreeNode* root, int& ans, int cur) {
        if (!root) return;
        cur += root->val;
        if (!root->left && !root->right) {
            ans += cur;
            return;
        }
        dfs(root->left, ans, cur * 2);
        dfs(root->right, ans, cur * 2);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        auto ans{0};
        dfs(root, ans, 0);
        return ans;
    }
};