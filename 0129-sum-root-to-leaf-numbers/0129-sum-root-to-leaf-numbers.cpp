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
public:
    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }
    
    // only go down "root-to-leaf paths" which are valid
    // if we go down an invalid path, discard it (will be handled correctly)
    int helper(TreeNode* root, int val) {
        // cout << (root ? (root->val) : -1) << " " << val << "\n";
        if (!root) return 0;
        if (!root->left && !root->right) return val * 10 + root->val;
        return helper(root->left, val * 10 + root->val)
                + helper(root->right, val * 10 + root->val);
    }
};
// [1,0]