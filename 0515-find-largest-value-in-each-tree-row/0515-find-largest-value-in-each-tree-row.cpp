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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        queue<TreeNode*> next;
        TreeNode* cur;
        int maxVal;
        if (!root) return ans;        
        q.push(root);
        while (!q.empty()) {
            maxVal = INT_MIN;
            while (!q.empty()) {
                cur = q.front();
                q.pop();
                if (cur->left) next.push(cur->left);
                if (cur->right) next.push(cur->right);
                maxVal = max(maxVal, cur->val);
            }
            swap(next, q);
            ans.push_back(maxVal);
        }
        return ans;
    }
};
// []