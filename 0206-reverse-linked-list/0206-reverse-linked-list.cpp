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
    // recursive
    // ListNode* reverseList(ListNode* head, ListNode* ans = nullptr) {
    //     if (!head) return ans;
    //     ListNode* next = head->next;
    //     head->next = ans;
    //     return reverseList(next, head);
    // }
    
    // iterative
    // extract first node, store in temp
    // move node to next
    // point first node to ans
    // set ans to first node (which is pointing at ans)
    ListNode* reverseList(ListNode* head) {
        ListNode* ans = nullptr;
        ListNode* temp = nullptr;
        while (head) {
            temp = head;
            head = head->next;
            temp->next = ans;
            ans = temp;
        }
        return ans;
    }
};