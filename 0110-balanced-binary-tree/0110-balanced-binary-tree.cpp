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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        auto [leftFlag, left] = helper(root->left);
        auto [rightFlag, right] = helper(root->right);
        if (!leftFlag || !rightFlag) return false;
        return (abs(right - left) <= 1);
    }
    
    // <is_balanced, height>
    pair<bool,int> helper(TreeNode* root) {
        if (!root) return {true, 0};
        auto [leftFlag, left] = helper(root->left);
        auto [rightFlag, right] = helper(root->right);
        return {leftFlag && rightFlag && abs(right - left) <= 1, 1 + max(left, right)};
    }
};
// [1,2,2,3,null,null,3,4,null,null,4]