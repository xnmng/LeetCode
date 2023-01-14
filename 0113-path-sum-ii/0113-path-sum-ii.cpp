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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> cur;
        vector<vector<int>> ans;
        auto curSum{0};
        if (root) {
            dfs(root, cur, curSum, ans, targetSum);
        }
        return ans;
    }
private:
    void dfs(TreeNode* root, vector<int>& cur, int& curSum, vector<vector<int>>& ans, int& targetSum) {
        cur.push_back(root->val);
        curSum += root->val;
        if (curSum == targetSum && !(root->left) && !(root->right)) {
            ans.push_back(cur);
        } else {
            if (root->left) {
                dfs(root->left, cur, curSum, ans, targetSum);
            }
            if (root->right) {
                dfs(root->right, cur, curSum, ans, targetSum);
            }
        }
        cur.pop_back();
        curSum -= root->val;
    }
};