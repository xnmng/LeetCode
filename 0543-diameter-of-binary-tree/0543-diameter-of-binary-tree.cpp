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

// TODO: stack solution
// https://leetcode.com/problems/diameter-of-binary-tree/discuss/3647520/Diameter-of-BST-with-Stack-and-Hashmap

// recursive solution
// https://leetcode.com/problems/diameter-of-binary-tree/discuss/573591/C++-5-lines-O(n)-solution
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        helper(root, ans);
        return ans;
    }
    
    // returns longest path, attempts to calculate answer at each step
    int helper(TreeNode* root, int& ans) {
        if (!root) return 0;
        int left = helper(root->left, ans);
        int right = helper(root->right, ans);
        ans = max(ans, left + right);
        return 1 + max(left, right);
    }
};