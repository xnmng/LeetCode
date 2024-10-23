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
    // BFS 2 pass 
    // O(n) time, O(n) space
    // use id to determine if parent
    TreeNode* replaceValueInTree(TreeNode* root) {
        int levelsum;
        int id;
        vector<int> v{0};
        queue<pair<int, TreeNode*>> q;
        queue<pair<int, TreeNode*>> next;
        q.emplace(0, root);
        while (!q.empty()) {
            levelsum = 0;
            id = 0;
            while (!q.empty()) {
                // actually parent_id (some arbitrary id given)
                auto [parent, cur] = q.front();
                q.pop();
                levelsum += cur->val;
                v[parent] += cur->val;
                next.emplace(parent, cur);
            }
            while (!next.empty()) {
                auto [parent, cur] = next.front();
                next.pop();
                // cout << parent << "\n";
                // cout << cur->val << " " << levelsum << " " << v[parent] << "\n";
                cur->val = levelsum - v[parent];
                if (cur->left) q.emplace(id, cur->left);
                if (cur->right) q.emplace(id, cur->right);
                ++id;
            }
            v.reserve(id);
            fill(v.begin(), v.end(), 0);
            while (v.size() < id) v.emplace_back(0);
        }
        return root;
    }
};
// [33,37,42,null,null,null,46]