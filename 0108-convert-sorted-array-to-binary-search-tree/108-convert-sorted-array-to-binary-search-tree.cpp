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
    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (left >= right) return nullptr;
        if (left+1 == right) return new TreeNode(nums[left]);
        auto mid{(right-left)/2 + left};
        auto ans{new TreeNode(nums[mid])};
        ans->left = helper(nums, left, mid);
        ans->right = helper(nums, mid+1, right);
        return ans;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size());
    }
};