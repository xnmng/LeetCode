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
    // assumes ListNodes to be deleted dont need to be deleted
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s(nums.begin(), nums.end());
        // alternatively, can just skip head until the first node does not need to be deleted
        ListNode* ans = new ListNode(0); // dummy node
        ListNode* ansTail = ans;
        while (head) {
            if (s.find(head->val) == s.end()) {
                ansTail->next = head;
                ansTail = ansTail->next;
            }
            head = head->next;
        }
        
        // set tail to nullptr, clean up heap memory and return
        ansTail->next = nullptr;
        auto temp = ans;
        ans = ans->next;
        delete temp;
        return ans;
    }
};