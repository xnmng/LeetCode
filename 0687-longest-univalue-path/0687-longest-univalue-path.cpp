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
private:
    pair<int,int> dfs(TreeNode* root, int& ans) {
        if (!root) return {INT_MAX,0};
        auto [leftVal, leftPath] = dfs(root->left, ans);
        auto [rightVal, rightPath] = dfs(root->right, ans);
        auto len{0};
        auto path{0};
        if (leftVal == root->val) {
            len += 1 + leftPath;
            path = max(path, 1 + leftPath);
        }
        if (rightVal == root->val) {
            len += 1 + rightPath;
            path = max(path, 1 + rightPath);
        }
        if (len == 1) cout << root->val << " " << len << "\n";
        ans = max(ans, len);
        return {root->val, path};
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        auto ans{0};
        // auto res = 
        dfs(root, ans);
        // cout << res.first << " " << res.second << "\n";
        return ans;
    }
};

// [-9,5,0,-2,-6,null,null,5,null,null,-3,6,-5,null,null,null,0]