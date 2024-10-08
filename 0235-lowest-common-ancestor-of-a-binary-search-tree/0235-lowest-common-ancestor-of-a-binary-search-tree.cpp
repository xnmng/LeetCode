/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // utilize BST property
    // LCA of p and q is between p and q (i.e. p <= root <= q)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root->val > p->val && root->val > q->val) {
            if (root->left) return lowestCommonAncestor(root->left, p, q);
        }        
        else if (root->val < p->val && root->val < q->val) {
            if (root->right) return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};