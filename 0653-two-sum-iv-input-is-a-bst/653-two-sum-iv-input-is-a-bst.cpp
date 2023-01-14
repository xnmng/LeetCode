// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/discuss/106059/JavaC++-Three-simple-methods-choose-one-you-like

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
    bool search(TreeNode* root, int target, TreeNode* cur) {
        if (!root) return false;
        // cout << root->val << " " << cur->val << "\n";
        if (root->val + cur->val == target && root != cur) return true;
        return root->val > target - cur->val
            ? search(root->left, target, cur) 
            : search(root->right, target, cur);
    }
    
    void dfs(TreeNode* cur, int k, bool& ans, TreeNode* root) {
        if (ans || !cur) return;
        // cout << cur->val << "\n";
        if (search(root, k, cur)) {
            ans = true;
            return;
        }
        dfs(cur->left, k, ans, root);
        dfs(cur->right, k, ans, root);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        auto ans{false};
        dfs(root, k, ans, root);
        return ans;
    }
};

// impl bug (branch condition for search)
// [236,104,701,null,227,null,911]
// 331