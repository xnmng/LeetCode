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
    ListNode* partition(ListNode* head, int x) {
        auto left{new ListNode()}; // dummy head
        auto leftTail{left};
        auto right{new ListNode()};
        auto rightTail{right};
        while (head) {
            // cout << head->val << "\n";
            if (head->val < x) {
                leftTail->next = head;
                leftTail = leftTail->next;
            } else {
                rightTail->next = head;
                rightTail = rightTail->next;
            }
            head = head->next;
        }
        leftTail->next = right->next;
        rightTail->next = nullptr;
        return left->next;
    }
};