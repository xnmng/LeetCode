// https://leetcode.com/problems/delete-nodes-and-return-forest/discuss/328853/JavaC++Python-Recursion-Solution

// If a node is root (has no parent) and isn't deleted, add it to the result.

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
    void helper(TreeNode* root, TreeNode* prev, vector<TreeNode*>& ans, unordered_set<int>& s) {
        if (!root) return;
        if (s.find(root->val) != s.end()) {
            if (prev && prev->left == root) prev->left = nullptr;
            if (prev && prev->right == root) prev->right = nullptr;
            auto left{root->left};
            auto right{root->right};
            delete root;
            helper(left, nullptr, ans, s);
            helper(right, nullptr, ans, s);
        }
        else {
            if (!prev) ans.push_back(root);
            helper(root->left, root, ans, s);
            helper(root->right, root, ans, s);
        }
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_set<int> s(to_delete.begin(), to_delete.end());
        helper(root, nullptr, ans, s);
        return ans;
    }
};