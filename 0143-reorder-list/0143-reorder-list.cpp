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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        // stop 1 node before "halfway point" (e.g. 1234, slowptr stops at 2)
        // achieve this by checking for fast->next->next
        while (fast && fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next; // reuse fast ptr, since it was nullptr
        slow->next = nullptr;
        fast = reverse(fast);
        head = alternate(head, fast);
    }
    
    ListNode* reverse(ListNode* head, ListNode* ans = nullptr) {
        if (!head) return ans;
        ListNode* next = head->next;
        head->next = ans;
        return reverse(next, head);
    }
    
    ListNode* alternate(ListNode* a, ListNode* b) {
        if (!a) return a;
        ListNode* ans = new ListNode();
        ListNode* tail = ans;
        while (a && b) {
            tail->next = a;
            a = a->next;
            tail = tail->next;
            tail->next = b;
            b = b->next;
            tail = tail->next;
        }
        
        // edge case where both lists dont have same number of elements
        // (i.e. initial list is odd in total length)
        if (a) tail->next = a;
        else if (b) tail->next = b;
        
        // free up heap memory we created at the start, return remaining
        tail = ans->next;
        delete ans;
        return tail;
    }
};