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
    int pairSum(ListNode* head) {
        deque<int> dq;
        int ans{0};
        while (head) {
            dq.push_back(head->val);
            head = head->next;
        }
        while (!dq.empty()) {
            ans = max(ans, dq.front() + dq.back());
            dq.pop_front();
            dq.pop_back();
        }
        return ans;
    }
};