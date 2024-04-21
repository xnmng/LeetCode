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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> mp; // <subtree_sum, freq>
        int maximum = 0;
        dfs(root, mp, maximum);
        vector<int> ans;
        for (auto& [k,v] : mp) {
            if (v == maximum) ans.emplace_back(k);
        }
        return ans;
    }
    
    int dfs(TreeNode* root, unordered_map<int,int>& mp, int& maximum) {
        if (!root) return 0;
        int sum = root->val;
        sum += dfs(root->left, mp, maximum);
        sum += dfs(root->right, mp, maximum);
        ++mp[sum];
        maximum = max(maximum, mp[sum]);
        return sum;
    }
};