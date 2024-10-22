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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        long long sum;
        queue<TreeNode*> q;
        queue<TreeNode*> next;
        q.push(root);
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
            pq.push(sum);
            if (pq.size() > k) pq.pop();
            swap(q, next);
        }
        return pq.size() == k ? pq.top() : -1;
    }
};