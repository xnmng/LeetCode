/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// https://leetcode.com/problems/linked-list-cycle-ii/discuss/44781/Concise-O(n)-solution-by-using-C++-with-Detailed-Alogrithm-Description
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        auto slow{head};
        auto fast{head};
        auto start{head};
        while (fast && fast->next && fast->next->next) {      
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                while (slow != start) {
                    slow = slow->next;
                    start = start->next;
                }
                return start;
            }
        }
        return nullptr;
    }
};