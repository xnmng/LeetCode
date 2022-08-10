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
    void helper(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        if (!root->left && !root->right) {
            ans.push_back(root->val);
            return;
        }
        helper(root->left, ans);
        ans.push_back(root->val);
        helper(root->right, ans);
    }
    
    void merge(vector<int> root1, vector<int> root2, vector<int>& ans) {
        auto index1{0};
        auto index2{0};
        while (index1 < root1.size() || index2 < root2.size()) {
            if (index2 == root2.size()) {
                ans.push_back(root1[index1]);
                ++index1;
            }
            else if (index1 == root1.size()) {
                ans.push_back(root2[index2]);
                ++index2;
            }
            else {
                if (root1[index1] < root2[index2]) {
                    ans.push_back(root1[index1]);
                    ++index1;
                } else {
                    ans.push_back(root2[index2]);
                    ++index2;
                }
            }
        }
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1; 
        helper(root1, v1);
        vector<int> v2; 
        helper(root2, v2);
        vector<int> ans;
        merge(v1, v2, ans);
        return ans;
    }
};