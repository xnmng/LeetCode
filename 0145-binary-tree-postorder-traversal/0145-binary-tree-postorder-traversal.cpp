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
    // TODO: how do without reverse?
    // iterative solution
    // https://leetcode.com/problems/binary-tree-postorder-traversal/discuss/5686926/Iterative-+-recursive-or-100-or-C++-or-simple
    // use the property that inorder reversed is postorder
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> ans;
        TreeNode* prev = nullptr;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            auto cur = s.top();
            s.pop();
            ans.emplace_back(cur->val);
            if (cur->left) s.push(cur->left);
            if (cur->right) s.push(cur->right);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    // recursive solution
    // vector<int> postorderTraversal(TreeNode* root) {
    //     if (!root) return {};
    //     vector<int> ans{postorderTraversal(root->left)};
    //     auto right{postorderTraversal(root->right)};
    //     ans.insert(ans.end(), right.begin(), right.end());
    //     ans.emplace_back(root->val);
    //     return ans;
    // }
};