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
    bool check(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true;
        if (!root || !subRoot) return false;
        if (root->val == subRoot->val) {
            return check(root->left, subRoot->left) 
                && check(root->right, subRoot->right);
        }
        return false;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (check(root, subRoot)) return true;
        auto ans{false};
        if (root->left) ans = ans || isSubtree(root->left, subRoot);
        if (root->right) ans = ans || isSubtree(root->right, subRoot);
        return ans;
    }
};