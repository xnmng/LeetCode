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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            return new TreeNode(val, root, nullptr);
        }
        auto cur{2};
        queue<TreeNode*> q;
        q.push(root);
        while (cur < depth) {
            queue<TreeNode*> next;
            // cout << "level: " << cur << "\n";
            while (!q.empty()) {
                auto cur{q.front()};
                q.pop();
                // cout << cur->val << " ";
                if (cur->left) next.push(cur->left);
                if (cur->right) next.push(cur->right);
            }
            // cout << "\n\n";
            q = next;
            ++cur;
        }
        while (!q.empty()) {
            auto cur{q.front()};
            q.pop();
            // cout << cur->val << " ";
            auto left{new TreeNode(val, cur->left, nullptr)};
            cur->left = left;
            auto right{new TreeNode(val, nullptr, cur->right)};
            cur->right = right;
        }
        return root;
    }
};

// read the adding rule! 
// [1,2,3,4]
// 5
// 4
// [4,2,6,3,1,5]
// 1
// 3