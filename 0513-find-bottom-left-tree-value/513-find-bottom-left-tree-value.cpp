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
        auto ans{root->val};
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            ans = q.front()->val;
            queue<TreeNode*> next;
            while (!q.empty()) {
                auto cur{q.front()};
                q.pop();
                if (cur->left) {
                    next.push(cur->left);
                }
                if (cur->right) {
                    next.push(cur->right);
                }
            }
            q = next;
        }
        return ans;
    }
};