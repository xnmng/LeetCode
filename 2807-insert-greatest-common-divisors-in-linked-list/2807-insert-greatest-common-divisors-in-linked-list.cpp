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
    int findGcd(int a, int b) {
        if (b > a) return findGcd(b, a);
        if (b == 0) return a;
        return findGcd(b, a % b);
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        auto cur = head;
        ListNode* temp;
        while (cur && cur->next) {
            temp = new ListNode(findGcd(cur->val, cur->next->val));
            temp->next = cur->next;
            cur->next = temp;
            cur = cur->next->next;
        }
        return head;
    }
};