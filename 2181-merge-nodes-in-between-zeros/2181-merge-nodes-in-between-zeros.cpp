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
    // assume nodes are heap allocated using new
    ListNode* mergeNodes(ListNode* head) {
        ListNode* cur = head->next;
        ListNode* toAdd = cur->next;
        // cout << cur->val << " " << toAdd->val << "\n";
        while(toAdd) {
            while (toAdd->val != 0) {
                cur->val += toAdd->val;
                ListNode* temp = toAdd;
                toAdd = toAdd->next;
                // cout << "deleting " << temp->val << "\n";
                delete temp;
            }
            cur->next = toAdd->next;
            ListNode* temp = toAdd;
            // cout << "deleting " << temp->val << "\n";
            delete temp;
            cur = cur->next;
            if (!cur) break;
            toAdd = cur->next;
        }
        ListNode* temp = head;
        cur = head->next;
        delete temp;
        return cur;
    }
};