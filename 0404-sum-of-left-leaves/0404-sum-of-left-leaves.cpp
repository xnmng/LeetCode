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
    // left leaf := left child of another node with no children (2 criteria)
    int sumOfLeftLeaves(TreeNode* root, bool isLeft = false) {
        if (!root) return 0;
        return ((isLeft && !root->left && !root->right) ? root->val : 0) 
                + sumOfLeftLeaves(root->left, true) 
                + sumOfLeftLeaves(root->right, false);
    }
};
// [1,2,3,4,5]