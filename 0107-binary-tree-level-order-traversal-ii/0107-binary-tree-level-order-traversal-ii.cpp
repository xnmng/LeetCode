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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) q.push(root);
        queue<TreeNode*> next;
        vector<vector<int>> ans;
        TreeNode* cur;
        while (!q.empty()) {
            vector<int> v;
            while (!q.empty()) {
                cur = q.front();
                q.pop();
                v.push_back(cur->val);
                if (cur->left) next.push(cur->left);
                if (cur->right) next.push(cur->right);
            }
            swap(q, next);
            ans.push_back((v));
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};