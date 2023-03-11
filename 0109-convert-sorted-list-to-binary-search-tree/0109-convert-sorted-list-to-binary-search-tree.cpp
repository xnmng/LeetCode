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

// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/discuss/35483/My-Accepted-C++-solution
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head, ListNode* tail = nullptr) {
        if (head == tail) return nullptr;
        if (head->next == tail) return new TreeNode(head->val);
        auto slow{head};
        auto fast{head};
        while (fast->next != tail && fast->next->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto ans{new TreeNode(slow->val)};
        ans->left = sortedListToBST(head, slow);
        ans->right = sortedListToBST(slow->next, tail);
        return ans;
    }
};