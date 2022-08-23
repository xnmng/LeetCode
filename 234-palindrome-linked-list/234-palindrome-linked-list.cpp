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
    // O(n) time, O(n) space
    // bool isPalindrome(ListNode* head) {
    //     deque<int> dq;
    //     auto ptr{head};
    //     while (ptr) {
    //         dq.push_back(ptr->val);
    //         ptr = ptr->next;
    //     }
    //     while (!dq.empty()) {
    //         if (dq.front() == dq.back()) {
    //             dq.pop_front();
    //             // if deque only has 1 element left
    //             if (!dq.empty()) {
    //                 dq.pop_back();
    //             }
    //         } else return false;
    //     }
    //     return true;
    // }
    
    // O(n) time, O(1) space (no modification)
    ListNode* reverse(ListNode* head) {
        if (!head) return nullptr;
        auto ptr{head->next};
        ListNode* ans{head};
        head->next = nullptr;
        while (ptr) {
            ListNode* cur = ptr;
            ptr = ptr->next;
            cur->next = ans;
            ans = cur;
        }
        return ans;
    }
    bool isPalindrome(ListNode* head) {
        auto slow{head};
        auto fast{head};
        while (fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto second{slow->next};
        slow->next = nullptr;
        
        auto p2r{reverse(second)};
        auto p1{head};
        auto p2{p2r};
        
        while (p1 && p2) {
            if (p1->val != p2->val) {
                slow->next = reverse(p2r);
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        
        slow->next = reverse(p2r);
        return true;
    }
};

// 1 2 3 4
//   s f

// 1 2 3 4 5
//     s   f