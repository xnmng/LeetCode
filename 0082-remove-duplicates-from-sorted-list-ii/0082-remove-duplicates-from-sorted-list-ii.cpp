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
   // in reality, make sure that ListNode is stack allocated
    // otherwise, remember to delete the ptr to not leak memory!
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ans = nullptr;
        ListNode* ansTail = nullptr;
        while (head) {
            // single unique element; append it
            if (!head->next || head->val != head->next->val) {
                if (!ansTail) {
                    ans = head;
                    ansTail = head;
                } else {
                    ansTail->next = head;
                    ansTail = ansTail->next;
                }
                head = head->next;
            } else { // duplicate element; remove all instances
                int val = head->val;
                while (head && head->val == val) {
                    head = head->next;
                }
            }
        }
        if (ansTail) ansTail->next = nullptr;
        return ans;
    }
};
// [1,1]
// []