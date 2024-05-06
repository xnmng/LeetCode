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
    // O(n) time O(1) space (but 2 pass)
    // idea: we notice that if we traverse in reverse order, 
    //          we just need to remove nodes that are smaller than what comes before
    //          (easier than initial problem)
    //          to reduce the problem to a simpler version, 
    //          we just reverse the LL, solve the "easier version", then reverse back
    //
    // - reverse the LL
    // - remove smaller next elements
    // - reverse back (and return)
    ListNode* removeNodes(ListNode* head) {
        // (reversed) head will always be part of the answer, because of erase condition requiring 1 node before
        head = reverse(head);
        ListNode* cur = head->next; // setting cur to head will cause infinite loop
        ListNode* prev = head;
        // not sure if heap alloc or stack alloc nodes; assume its heap alloc 
        // (need to delete for new and free for malloc)
        while (cur) {
            if (prev->val > cur->val) {
                // delete the cur node
                ListNode* toDel = cur;
                
                prev->next = cur->next;
                cur = cur->next;
                
                delete toDel;
            }
            else {
                prev = cur;
                cur = cur->next;
            }
        }
        return reverse(head);
    }
    
    ListNode* reverse(ListNode* head) {
        ListNode* ans = nullptr;
        ListNode* temp = nullptr;
        while (head) {
            temp = head->next;
            head->next = ans;
            ans = head;
            head = temp;
        }
        return ans;
    }
};
    // // stack solution is O(n) time and O(n) space (trivial to implement)
    //     ListNode* removeNodes(ListNode* head) {
    //     stack<ListNode*> s;
    //     ListNode* cur;
    //     while (head) {
    //         while (!s.empty() && s.top()->val < head->val) {
    //             cur = s.top();
    //             // cout << "deleting " << cur->val << "\n";
    //             s.pop();
    //             delete(cur);
    //         }
    //         s.push(head);
    //         head = head->next;
    //     }
    //     // cout << "ok\n";
    //     cur = nullptr;
    //     while (!s.empty()) {
    //         if (!cur) {
    //             cur = s.top();
    //         } else {
    //             s.top()->next = cur;
    //             cur = s.top();
    //         }
    //         s.pop();
    //     }
    //     return cur;
    // }