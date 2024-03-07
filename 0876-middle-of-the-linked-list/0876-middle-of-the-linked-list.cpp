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
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        auto fast{head};
        auto slow{head};
        while (fast) {
            if (fast-> next && fast->next->next) {
                slow = slow->next;
                fast = fast->next->next;
            } else break;
        }
        // cout << fast->val << "\n";
        return fast && fast->next ? slow->next : slow;
    }
};