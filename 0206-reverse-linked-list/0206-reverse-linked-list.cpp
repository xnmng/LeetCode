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
    // TODO: recursive
    
    // iterative
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