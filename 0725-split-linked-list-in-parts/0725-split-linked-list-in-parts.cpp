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
    int getSize(ListNode* head) {
        int ans = 0;
        while (head) {
            ++ans;
            head = head->next;
        }
        return ans;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k);
        int size = getSize(head);
        // cout << "size:" << size << "\n";
        int index = 0;
        int count = 0;
        while (head) {
            if (count == 0) {
                // cout << "index:" << index << " val:" << head->val << "\n";
                ans[index] = head;
            }
            ++count;
            if ((index < (size % k) && count == (size / k) + 1) 
                || (index >= (size % k) && count == size / k)) {
                // cout << "count:" << count << "\n";
                count = 0;
                auto temp = head->next;
                head->next = nullptr;
                swap(temp, head);
                ++index;
            } else {
                head = head->next;            
            }
        }
        return ans;
    }
};