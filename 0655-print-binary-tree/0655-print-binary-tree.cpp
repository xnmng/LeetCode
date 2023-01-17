// https://leetcode.com/problems/print-binary-tree/discuss/113987/C++-Simple-solution-with-DFS-(pre-order-traversal)
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
private:
    int getHeight(TreeNode* root) {
        auto ans{0};
        if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        queue<TreeNode*> next;
        TreeNode* cur;
        while (!q.empty()) {
            ++ans;
            while (!q.empty()) {
                cur = q.front();
                q.pop();
                if (cur->left) next.push(cur->left);
                if (cur->right) next.push(cur->right);
            }
            swap(next, q);
        }
        return ans;
    }
    
    void dfs(TreeNode* cur, vector<vector<string>>& ans, int height, int left, int right) {
        ans[height][(right + left) / 2] = to_string(cur->val);
        if (cur->left) dfs(cur->left, ans, height+1, left, (right + left) / 2);        
        if (cur->right) dfs(cur->right, ans, height+1, (right + left) / 2, right);        
    }
public:
    vector<vector<string>> printTree(TreeNode* root) {
        auto h{getHeight(root)};
        vector<vector<string>> ans(h, vector<string>(pow(2, h) - 1));
        dfs(root, ans, 0, 0, ans[0].size());
        return ans;
    }
};