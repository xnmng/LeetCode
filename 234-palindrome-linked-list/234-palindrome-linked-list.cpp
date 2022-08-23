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
    bool isPalindrome(ListNode* head) {
        deque<int> dq;
        auto ptr{head};
        while (ptr) {
            dq.push_back(ptr->val);
            ptr = ptr->next;
        }
        while (!dq.empty()) {
            if (dq.front() == dq.back()) {
                dq.pop_front();
                if (!dq.empty()) {
                    dq.pop_back();
                }
            } else return false;
        }
        return true;
    }
};