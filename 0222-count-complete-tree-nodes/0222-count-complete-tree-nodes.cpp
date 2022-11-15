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

// https://leetcode.com/problems/count-complete-tree-nodes/discuss/1538170/C++-Simple-and-Concise-Recursive-Solution-O(logn-*-logn)
// https://youtu.be/CvrPf1-flAA
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        auto left{0};
        auto lptr{root};
        auto right{0};
        auto rptr{root};
        while (lptr) {
            ++left;
            lptr = lptr->left;
        }
        while (rptr) {
            ++right;
            rptr = rptr->right;
        }
        if (left == right) return static_cast<int>(pow(2, left)-1);
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};