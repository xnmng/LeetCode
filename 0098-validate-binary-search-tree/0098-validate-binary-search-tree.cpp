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


// in order traversal solution
//
// just traverse in order and make sure nodes are increasing
//
// https://leetcode.com/problems/validate-binary-search-tree/discuss/32104/C++-in-order-traversal-and-please-do-not-rely-on-buggy-INT_MAX-INT_MIN-solutions-any-more
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return helper(root, prev);
    }
    
    bool helper(TreeNode* root, TreeNode*& prev) {
        if (!root) return true;
        if (!helper(root->left, prev)) return false;
        if (prev && root->val <= prev->val) return false;
        prev = root;
        return helper(root->right, prev);
    }
};
    
    
//     // recursive solution
//     // bad practice to rely on INT_MAX and INT_MIN to compare, compare using the nodes themselves
//     bool helper(TreeNode* root, TreeNode* left = nullptr, TreeNode* right = nullptr) {
//         if (!root) return true;
//         if (left && left->val >= root->val) return false;
//         if (right && right->val <= root->val) return false;
//         return helper(root->left, left, root) 
//             && helper(root->right, root, right);
//     }
//     bool isValidBST(TreeNode* root) {
//         if (!root) return true;
//         return helper(root->left, nullptr, root)
//             && helper(root->right, root, nullptr);
//     }
// };

// [1,null,1]