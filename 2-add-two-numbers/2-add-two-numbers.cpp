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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto ans{new ListNode()}; // dummy node
        auto ansTail{ans};
        auto sum{0};
        auto carry{0};
        
        auto ptr1{l1};
        auto ptr2{l2};
        
        while (ptr1 || ptr2) {
            sum = carry;
            carry = 0;
            if (ptr1) sum += ptr1->val;
            if (ptr2) sum += ptr2->val;
            if (sum >= 10) {
                carry = sum/10;
                sum %= 10;
            }
            ansTail->next = new ListNode(sum);
            ansTail = ansTail->next;
            if (ptr1) ptr1 = ptr1->next;
            if (ptr2) ptr2 = ptr2->next;
        }
        
        if (carry > 0) {
            ansTail->next = new ListNode(carry);
        }
        
        return ans->next;
    }
};