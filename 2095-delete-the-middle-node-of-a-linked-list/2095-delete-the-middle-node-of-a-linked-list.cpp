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
    ListNode* deleteMiddle(ListNode* head) {
        if (!head->next) {
            // delete head;
            return nullptr;
        }
        auto fast{head->next->next}; // dont initialize this same as slow!
        auto slow{head};
        while (fast 
               && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        auto toDel{slow->next};
        slow->next = slow->next->next;
        // delete toDel;
        return head;
    }
};