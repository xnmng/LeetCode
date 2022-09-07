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
    string tree2str(TreeNode* root) {
        if (!root) return "";
        string ans{to_string(root->val)};
        auto left = tree2str(root->left);
        auto right = tree2str(root->right);
        // cout << "left: " << left << " right: " << right << "\n";
        if (left == "" && right == "") {}
        else if (right != "") {
            ans += "(" + left + ")(" + right + ")";
        } else {
            ans += "(" + left + ")";
        }
        return ans;        
    }
};