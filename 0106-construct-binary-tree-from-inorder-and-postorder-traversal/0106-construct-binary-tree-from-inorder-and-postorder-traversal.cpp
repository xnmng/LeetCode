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

// https://youtu.be/vm63HuIU7kw
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/discuss/1588934/C++-EASY-Intuitive-Sol-or-Clean-Recursive-Code-w-Explanation-(Dry-Run)-or-T.C:O(N)
class Solution {
private:
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, unordered_map<int,int>& mp, 
                     int left, int right, int& backIndex) {
        if (left > right) return nullptr;
        TreeNode* ans{new TreeNode(postorder[backIndex])};
        --backIndex;
        ans->right = helper(inorder, postorder, mp, mp[ans->val] + 1, right, backIndex);        
        ans->left = helper(inorder, postorder, mp, left, mp[ans->val] - 1, backIndex);
        return ans;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for (auto i = 0; i < inorder.size(); ++i) {
            mp[inorder[i]] = i;
        }
        auto index{static_cast<int>(postorder.size() - 1)};
        return helper(inorder, postorder, mp, 0, inorder.size() - 1, index);
    }
};