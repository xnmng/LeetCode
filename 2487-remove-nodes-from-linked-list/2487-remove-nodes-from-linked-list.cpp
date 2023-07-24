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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> s;
        ListNode* cur;
        while (head) {
            while (!s.empty() && s.top()->val < head->val) {
                cur = s.top();
                // cout << "deleting " << cur->val << "\n";
                s.pop();
                delete(cur);
            }
            s.push(head);
            head = head->next;
        }
        // cout << "ok\n";
        cur = nullptr;
        while (!s.empty()) {
            if (!cur) {
                cur = s.top();
            } else {
                s.top()->next = cur;
                cur = s.top();
            }
            s.pop();
        }
        return cur;
    }
};