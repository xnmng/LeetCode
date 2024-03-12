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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* front = new ListNode(0, head);
        ListNode* current = front;
        int prefixSum = 0;
        unordered_map<int, ListNode*> prefixSumToNode;
        while (current != nullptr) {
            // Add current's value to the prefix sum
            prefixSum += current->val;

            // If prefixSum is already in the hashmap, 
            // we have found a zero-sum sequence:
            if (prefixSumToNode.find(prefixSum) != prefixSumToNode.end()) {
                ListNode* prev = prefixSumToNode[prefixSum];
                current = prev->next;

                // Delete zero sum nodes from hashmap
                // to prevent incorrect deletions from linked list
                int p = prefixSum + current->val;
                while (p != prefixSum) {
                    prefixSumToNode.erase(p);
                    current = current->next;
                    p += current->val;
                }

                // Make connection from the node before 
                // the zero sum sequence to the node after
                prev->next = current->next;
            } else {
                // Add new prefixSum to hashmap
                prefixSumToNode[prefixSum] = current;
            }
            // Progress to next element in list
            current = current->next;
        }
        return front->next;
    }
    
    // TODO: write my own explanation
    // can return any such answer; dont overthink it! 
    // (no need shortest length or wtv; separate problem)
    //
    // hashmap prefix sum:
    // store in hashmap (prefix_sum, ptr_to_node)
    // - iterate across list (starting from dummy)
    // - if previous prefix sum exists, remove nodes in between
    // - add new prefix sum into hashmap
    // - return dummy->next
//     ListNode* removeZeroSumSublists(ListNode* head) {
//         // create a dummy head because there could be a case the head node gets deleted
//         ListNode* dummy = new ListNode(0, head);
//         ListNode* cur = dummy;
//         ListNode* toDelete;
//         int sum = 0;
//         unordered_map<int, ListNode*> mp;
//         while (temp) {
//             sum += temp->val;
            
//             if (mp.find(sum) == mp.end()) mp[sum] = cur;
//             else {
//                 // note: we are assuming the linked list is heap memory (C++)
//                 toDelete = mp[sum];
//                 mp[sum]->next = cur;
//                 while (toDelete != )
//             }
            
//             cur = cur->next;
//         }
        
//         // note: we are assuming the linked list is heap memory (C++)
//         cur = dummy->next;
//         free dummy;
//         return cur;
//     }
};
// [1, -1]