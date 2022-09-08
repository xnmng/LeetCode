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
    void iot(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        iot(root->left, ans);
        ans.push_back(root->val);
        iot(root->right, ans);        
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        iot(root, ans);
        return ans;
    }
};