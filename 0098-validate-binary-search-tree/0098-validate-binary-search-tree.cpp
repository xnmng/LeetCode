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


// do in order traversal
// https://leetcode.com/problems/validate-binary-search-tree/discuss/32104/C++-in-order-traversal-and-please-do-not-rely-on-buggy-INT_MAX-INT_MIN-solutions-any-more
class Solution {
public:
//     bool isValidBST(TreeNode* root) {
//         auto [_, flag] = helper(root);
//         return flag;
//     }
    
//     // <prev_value, is_bst>
//     pair<int, bool> helper(TreeNode* root) {
        
//     }
// };
    
    
    // bad practice to rely on INT_MAX and INT_MIN to compare, compare using the nodes themselves
    bool helper(TreeNode* root, TreeNode* left = nullptr, TreeNode* right = nullptr) {
        if (!root) return true;
        if (left && left->val >= root->val) return false;
        if (right && right->val <= root->val) return false;
        return helper(root->left, left, root) 
            && helper(root->right, root, right);
    }
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        return helper(root->left, nullptr, root)
            && helper(root->right, root, nullptr);
    }
};