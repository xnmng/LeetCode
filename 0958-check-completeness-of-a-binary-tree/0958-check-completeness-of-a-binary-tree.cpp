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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* prev{root};
        TreeNode* cur;
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            if (cur) {
                if (prev == nullptr) return false;
                q.push(cur->left);
                q.push(cur->right);
            }
            prev = cur;
        }
        return true;
    }
};