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

// rewatch this + read solution
// https://youtu.be/YfdfIOeV_RU?si=_ushn-fo6CFU_llY
class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        helper(root, ans);
        return ans;
    }
    
    // returns <size_of_subtree, coins_in_subtree>
    pair<int,int> helper(TreeNode* root, int& ans) {
        if (!root) return {0, 0};
        auto [leftSize, leftCoins] = helper(root->left, ans);
        auto [rightSize, rightCoins] = helper(root->right, ans);
        int size = 1 + leftSize + rightSize;
        int coins = root->val + leftCoins + rightCoins;
        ans += abs(coins - size);
        return {size, coins};
    }
};