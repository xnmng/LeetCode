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
    void dfs(TreeNode* root, int& sum) {
        if (!root) return;
        dfs(root->right, sum);            
        root->val += sum;
        sum = root->val;
        dfs(root->left, sum);            
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        if (!root) return nullptr;
        auto sum{0};
        dfs(root, sum);
        return root;        
    }
};