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
private:
    // ListNode* merge(ListNode* s1, ListNode* s2) {
    //     if (!s1) return s2;
    //     if (!s2) return s1;
    //     if (s1->val <= s2->val) {
    //         s1->next = merge(s1->next, s2);
    //         return s1;
    //     } else {
    //         s2->next = merge(s1, s2->next);
    //         return s2;
    //     }
    // }

    ListNode* merge(ListNode* s1, ListNode* s2) {
        auto dummy{ListNode()};
        auto ans{&dummy};
        while (s1 || s2) {
            if (!s1) {
                ans->next = s2;
                s2 = s2->next;
            }
            else if (!s2) {
                ans->next = s1;
                s1 = s1->next;
            }
            else if (s1->val < s2->val) {
                ans->next = s1;
                s1 = s1->next;
            }
            else {
                ans->next = s2;
                s2 = s2->next;
            }
            ans = ans->next;
        }
        return dummy.next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        auto s{static_cast<int>(lists.size() - 1)};
        auto i{0};
        while (s > 0) {
            i = 0;
            while (i < s) {
                lists[i] = merge(lists[i], lists[s]);
                --s;
            }
        }
        return lists[0];
    }
};