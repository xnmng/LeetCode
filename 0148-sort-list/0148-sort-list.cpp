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
    void printlist(ListNode* cur) {
        while (cur) {
            cout << cur->val << "->";
        }
        cout << "\n";
    }
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = nullptr;
        slow = head;
        slow = sortList(slow);
        fast = sortList(fast);
        
        // dummy node
        ListNode* ans = new ListNode();
        ListNode* ansTail = ans;
        while (slow || fast) {
            if (!slow || !fast) {
                ansTail->next = (slow ? slow : fast);
                ansTail = ansTail->next;
                break;
            }
            if (slow->val > fast->val) {
                ansTail->next = fast;
                ansTail = ansTail->next;
                fast = fast->next;
            } else {
                ansTail->next = slow;
                ansTail = ansTail->next;
                slow = slow->next;
            }
        }
        
        // clean up dummy node before returning
        ListNode* temp = ans;
        ans = ans->next;
        delete(temp);
        return ans;
    }
};
// [1,2,3,4]