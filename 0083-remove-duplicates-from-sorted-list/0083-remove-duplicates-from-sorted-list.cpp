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
        ListNode* ans = head;
        ListNode* ansTail = head;
        if (!head) return ans;
        head = head->next;
        while (head) {
            if (head->val != ansTail->val) {
                ansTail->next = head;
                ansTail = ansTail->next;
            }
            head = head->next;
        }
        ansTail->next = nullptr;
        return ans;
    }
};