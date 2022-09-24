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
    void dfs(TreeNode* root, long& cur, unordered_map<long,int>& s, int& targetSum, int& ans) {
        if (!root) return;
        cur += root->val;
        // cout << root->val << " " << cur << "\n";
        if (s[cur - targetSum] > 0) {
            ans += s[cur - targetSum];
            // cout << "found at " << cur << "\n";
        }
        if (cur == targetSum) ++ans;
        ++s[cur];
        // cout << "insert " << cur << "\n";
        dfs(root->left, cur, s, targetSum, ans);
        dfs(root->right, cur, s, targetSum, ans);
        --s[cur];
        // cout << "erase " << cur << "\n";
        cur -= root->val;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        auto cur{0l};
        auto ans{0};
        unordered_map<long,int> s;
        dfs(root, cur, s, targetSum, ans);
        return ans;
    }
};

// handle case of duplicates; use unordred_map
// handle case where sum from root is targetSum; increment separately

// use long to represent 10^12/10^-12 maximum/minimum sum

// [0,1,1]
// 1
// [1000000000,1000000000,null,294967296,null,1000000000,null,1000000000,null,1000000000]
// 0