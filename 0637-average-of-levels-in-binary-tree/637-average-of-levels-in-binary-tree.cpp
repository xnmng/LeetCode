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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            long sum{0};
            auto count{0};
            queue<TreeNode*> next;
            while (!q.empty()) {
                auto cur{q.front()};
                q.pop();
                sum += cur->val;
                ++count;
                if (cur->left) next.push(cur->left);
                if (cur->right) next.push(cur->right);
            }
            ans.push_back(1.0 * sum / count);
            q = next;
        }
        return ans;
    }
};

// [2147483647,2147483647,2147483647]