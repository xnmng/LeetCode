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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head; // early return
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev;
        head = dummy;
        int index = 0;
        while (index != left && head) {
            prev = head;
            head = head->next;
            ++index;
        }
        // here, index == left (head points to node at index left)
        // cout << index << " " << head->val << " " << prev->val << "\n";
        ListNode* cur;
        ListNode* newRight = head;
        ListNode* newLeft = head;
        head = head->next;
        ++index;
        while (index <= right && head) {
            cur = head;
            head = head->next;
            ++index;
            cur->next = newLeft;
            newLeft = cur;
        }
        // here, head points to node at index (right+1)
        // cout << index << " " << head->val << " " << prev->val << " "<< newLeft->val << " " << newRight->val << "\n";
        prev->next = newLeft;
        newRight->next = head; 
        
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};