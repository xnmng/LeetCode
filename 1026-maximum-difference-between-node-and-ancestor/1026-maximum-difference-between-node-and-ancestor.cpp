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
    // could use vector<int> to store the path,
    // alternatively, we could simply store the max and min value of ancestor
    // void dfs(TreeNode* root, int& ans, vector<int>& v) {
    //     if (!root) return;
    //     for (auto i : v) {
    //         ans = max(abs(root->val - i), ans);
    //     }
    //     v.push_back(root->val);
    //     dfs(root->left, ans, v);
    //     dfs(root->right, ans, v);
    //     v.pop_back();
    // }
    
    void dfs(TreeNode* root, int& ans, int maximum, int minimum) {
        if (!root) return;
        ans = max(ans, abs(maximum - root->val));
        ans = max(ans, abs(root->val - minimum));
        dfs(root->left, ans, max(root->val, maximum), min(root->val, minimum));
        dfs(root->right, ans, max(root->val, maximum), min(root->val, minimum));
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        auto ans{0};
        vector<int> v;
        dfs(root, ans, root->val, root->val);
        // dfs(root, ans, v);
        return ans;
    }
};