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
    //bfs, be careful when checking conditions
    bool isEvenOddTree(TreeNode* root) {
        int level = 0;
        int prev = 0; // for even levels, set to 0, for odd levels, set to INT_MAX
        TreeNode* cur;
        queue<TreeNode*> q;
        queue<TreeNode*> next;
        q.push(root);
        while (!q.empty()) {
            while (!q.empty()) {
                cur = q.front();
                q.pop();
                if (level % 2 == 0 && (prev >= cur->val || cur->val % 2 == 0)) return false;
                if (level % 2 == 1 && (prev <= cur->val || cur->val % 2 == 1)) return false;
                if (cur->left) next.push(cur->left);
                if (cur->right) next.push(cur->right);
                prev = cur->val;
            }
            ++level;
            prev = (level % 2 == 0) ? 0 : INT_MAX;
            swap(q, next);
        }
        return true;
    }
};