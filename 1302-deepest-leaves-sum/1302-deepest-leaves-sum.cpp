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
    // deepest leaves -> highest depth -> BFS, return last known depth sum
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        queue<TreeNode*> next;
        q.push(root);
        int ans = 0;
        int sum;
        TreeNode* cur;
        while (!q.empty()) {
            sum = 0;
            while (!q.empty()) {
                cur = q.front();
                q.pop();
                sum += cur->val;
                if (cur->left) next.push(cur->left);
                if (cur->right) next.push(cur->right);
            }
            swap(q, next);
            ans = sum;
        }
        return ans;
    }
};