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
    void dfs(TreeNode* root, int& count, int maxSoFar) {
        if (!root) return;
        if (maxSoFar <= root->val) ++count;
        dfs(root->left, count, max(maxSoFar, root->val));
        dfs(root->right, count, max(maxSoFar, root->val));
    }
public:
    int goodNodes(TreeNode* root) {
        auto ans{0};
        dfs(root, ans, root->val);
        return ans;
    }
};