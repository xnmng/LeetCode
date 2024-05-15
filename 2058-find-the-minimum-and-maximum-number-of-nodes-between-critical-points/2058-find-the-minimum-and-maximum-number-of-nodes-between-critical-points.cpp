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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> v{-1, -1};
        if (!head->next->next) return v;
        vector<int> dist;
        auto cur = head->next->next;
        auto prev = head->next;
        auto prevprev = head;
        int count = 0;
        while (cur) {
            // cout << cur->val << " " << prev->val << " " << prevprev->val << "\n";
            if (prev->val > cur->val && prev->val > prevprev->val 
                || prev->val < cur->val && prev->val < prevprev->val) {
                dist.emplace_back(count);
                // cout << prev->val << " " << count << "\n";
            }
            ++count;
            prevprev = prev;
            prev = cur;
            cur = cur->next;
        }
        if (dist.size() < 2) return v;
        v[0] = dist[1] - dist[0];
        for (int i = 2; i < dist.size(); ++i) {
            v[0] = min(v[0], dist[i] - dist[i-1]);
        }
        v[1] = dist.back() - dist.front();
        return v;
    }
};