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
    // could also implement solution using stack for O(N) 1 pass, O(N) space
    //
    // O(N) 2 pass, O(1) space
    // reverse the LL, perform multiplication step/node-wise, then reverse back and return
    ListNode* doubleIt(ListNode* head) {
        head = reverseList(head);
        bool carry = false;
        ListNode* cur = head;
        ListNode* prev;
        while (cur) {
            cur->val *= 2;
            if (carry) ++cur->val;
            carry = cur->val >= 10;
            cur->val %= 10;
            prev = cur;
            cur = cur->next;
        }
        if (carry) prev->next = new ListNode(1);
        return reverseList(head);
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* ans = nullptr;
        ListNode* temp = nullptr;
        while (head) {
            temp = head->next;
            head->next = ans;
            ans = head;
            head = temp;
        }
        return ans;
    }
};