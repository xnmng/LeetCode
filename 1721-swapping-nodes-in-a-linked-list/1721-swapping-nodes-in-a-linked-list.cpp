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
    ListNode* swapNodes(ListNode* head, int k) {
        auto slow{head};
        auto fast{head};
        auto count{k};
        while (fast) {
            fast = fast->next;
            if (count > 0) {
                --count;
            } else {
                slow = slow->next;
            }
        }
        // cout << slow->val << "\n";
        fast = head;
        count = k-1;
        while (count > 0) {
            fast = fast->next;
            --count;
        }
        swap(slow->val, fast->val);
        return head;
    }
};