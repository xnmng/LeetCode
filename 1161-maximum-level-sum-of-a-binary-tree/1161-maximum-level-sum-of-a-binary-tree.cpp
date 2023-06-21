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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        queue<TreeNode*> next;
        q.push(root);
        auto ans{-1};
        auto maxSum{INT_MIN};
        auto level{1};
        auto sum{0};
        TreeNode* cur;
        while (!q.empty()) {
            while (!q.empty()) {
                cur = q.front();
                q.pop();
                sum += cur->val;
                if (cur->left) next.push(cur->left);
                if (cur->right) next.push(cur->right);
            }
            if (sum > maxSum) {
                ans = level;
                maxSum = sum;
            }
            swap(next, q);
            sum = 0;
            ++level;
        }
        return ans;
    }
};
// [1]