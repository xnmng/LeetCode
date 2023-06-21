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
    void dfs(TreeNode* root, int& prev, int& ans) {
        if (!root) return;
        if (root->left) dfs(root->left, prev, ans);
        // cout << root->val << "\n";
        if (prev != -1) {
            ans = min(ans, root->val - prev);
        }
        prev = root->val;
        if (root->right) dfs(root->right, prev, ans);        
    }
public:
    int getMinimumDifference(TreeNode* root) {
        auto prev{-1};
        auto ans{INT_MAX};
        dfs(root, prev, ans);
        return ans;
    }
};

// [1,null,3,2]