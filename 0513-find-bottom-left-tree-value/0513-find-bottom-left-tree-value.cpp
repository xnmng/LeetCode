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
    // bfs and find leftmost value
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        queue<TreeNode*> next;
        q.push(root);
        int ans;
        while (!q.empty()) {
            ans = q.front()->val;
            while (!q.empty()) {
                if (q.front()->left) next.push(q.front()->left);
                if (q.front()->right) next.push(q.front()->right);
                q.pop();
            }
            swap(q, next);
        }
        return ans;
    }
};