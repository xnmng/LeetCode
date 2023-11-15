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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<pair<int,int>> s; // <index, val>
        int index = 0;
        while (head) {
            while (!s.empty() && s.top().second < head->val) {
                ans[s.top().first] = head->val;
                s.pop();
            }
            s.emplace(index, head->val);
            ans.emplace_back(0);
            head = head->next;
            ++index;
        }
        return ans;
    }
};