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
    // bfs might TLE/MLE (?)
    TreeNode* reverseOddLevels(TreeNode* root) {
        helper(root->left, root->right, true);
        return root;
    }

    void helper(TreeNode* left, TreeNode* right, bool isOdd) {
        if (!left) return; // perfect binary tree; checking one is enough
        if (isOdd) swap(left->val, right->val);
        helper(left->left, right->right, isOdd ^ true);
        helper(left->right, right->left, isOdd ^ true);
    }
};