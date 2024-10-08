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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        queue<TreeNode*> next;
        q.push(root);
        TreeNode* cur;
        while (!q.empty()) {
            vector<int> v;
            while(!q.empty()) {
                cur = q.front();
                q.pop();
                v.push_back(cur->val);
                if (cur->left) next.push(cur->left);
                if (cur->right) next.push(cur->right);
            }
            ans.emplace_back(move(v));
            swap(q, next);
        }
        return ans;
    }
};