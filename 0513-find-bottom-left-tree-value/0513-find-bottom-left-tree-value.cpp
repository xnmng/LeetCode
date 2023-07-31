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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* cur;
        TreeNode* ans;
        while (!q.empty()) {
            queue<TreeNode*> next;
            ans = q.front();
            while (!q.empty()) {
                cur = q.front();
                q.pop();
                if (cur->left) next.push(cur->left);
                if (cur->right) next.push(cur->right);
            }
            swap(next, q);
        }
        return ans->val;
    }
};