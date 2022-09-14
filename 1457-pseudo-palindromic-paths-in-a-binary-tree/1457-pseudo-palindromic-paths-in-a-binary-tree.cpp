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
    int pseudoPalindromicPaths (TreeNode* root) {
        auto ans{0};
        vector<int> count(10,0);
        dfs(root, count, ans);
        return ans;
    }
private:
    void dfs(TreeNode* root, vector<int>& count, int& ans) {
        ++count[root->val];
        if (!root->left && !root->right) {
            auto odd{0};
            for (auto i : count) {
                if (i % 2 == 1) ++odd;
            }
            if (odd <= 1) ++ans;
        } else {
            if (root->left) {
                dfs(root->left, count, ans);
            }
            if (root->right) {
                dfs(root->right, count, ans);
            }
        }
        --count[root->val];
    }
};