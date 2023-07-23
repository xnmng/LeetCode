// https://youtu.be/nZtrZPTTCAo

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
    TreeNode* cloneTree(TreeNode* node) {
        if (!node) return node;
        auto clone = node;
        clone->left = cloneTree(node->left);
        clone->right = cloneTree(node->right);
        return clone;
    }
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<vector<TreeNode*>> dp(n+1);
        dp[1] = {new TreeNode(0)}; // base case
        TreeNode* root;
        for (auto i = 1; i <= n; i += 2) {
            for (auto j = 1; j+1 <= i; j += 2) { // left subtree
                // cout << i << " " << "left: " << j << " " << "right: " << i - 1 - j << "\n";
                for (auto& left : dp[j]) {
                    for (auto& right : dp[i-1-j]) {
                        root = new TreeNode(0);
                        root->left = cloneTree(left);
                        root->right = cloneTree(right);
                        dp[i].emplace_back(move(root));
                    }
                }
            }
        }
        return dp[n];
    }
};