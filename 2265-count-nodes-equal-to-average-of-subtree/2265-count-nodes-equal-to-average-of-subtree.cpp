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
    // return sum, count
    pair<int,int> helper(TreeNode* root, int& ans) {
        if (!root) return {0,0};
        auto [leftSum, leftCount] = helper(root->left, ans);
        auto [rightSum, rightCount] = helper(root->right, ans);
        int totalSum = leftSum + rightSum + root->val;
        int totalCount = 1 + leftCount + rightCount;
        if (totalSum / totalCount == root->val) ++ans;
        return {totalSum, totalCount};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        helper(root, ans);
        return ans;
    }
};