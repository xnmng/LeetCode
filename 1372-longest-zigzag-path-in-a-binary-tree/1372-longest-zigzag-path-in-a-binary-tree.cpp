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
    void dfs(TreeNode* root, int& ans, bool isLeft, int count) {
        if (!root) return;
        ans = max(count, ans);
        if (isLeft) {
            dfs(root->right, ans, false, count + 1);
            dfs(root->left, ans, true, 1);
        } else {
            dfs(root->left, ans, true, count + 1);
            dfs(root->right, ans, false, 1);
        }
    }
public:
    int longestZigZag(TreeNode* root) {
        auto ans{0};
        dfs(root, ans, true, 0);
        return ans;
    }
};