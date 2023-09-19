/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool helper(ListNode* head, TreeNode* root) {
        if (!head) return true;
        if (!root) return false;
        return head->val == root->val && (helper(head->next, root->left) || helper(head->next, root->right));
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false; // prevent nullptr access
        return helper(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};

// [10,7,4,10,2,6,10,10,10,1,10,6]
// [1,10,7,10,8,6,1,10,7,1,10,4,3,9,null,10,10,4,10,7,1,3,7,null,null,7,9,6,3,null,null,8,10,10,3,1,1,null,null,null,null,null,2,null,null,10,3,5,null,null,null,6,null,5,null,null,6,2,5,null,4,null,10,9,10,null,null,null,3,10,8,5,6,null,7,3,null,8,9,6,2,null,8,9,10,10,null,4,6,4,null,null,2,5,6,null,null,null,null,6,null,1,null,null,null,null,8,null,null,10,10,null,null,null,8,null,null,3,10,null,null,10,2,null,null,7,6,null,null,null,null,null,null,null,null,null,null,4,null,null,10,null,2,null,null,1,6,null,null,8,9,null,null,null,8,4,null,null,null,10,4,null,1,null,null,null,null,9,null,null,null,null,null,9,null,10,1,6,null,null,null,null,null,null,null,5,null,2,10,null,null,null,null,null,null,null,6,null,5]