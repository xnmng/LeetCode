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
    // might be UB; unsure if pointers are to stack/heap memory
    // if its heap memory, unsure if it was allocated using new/malloc
    // alternative is to leak memory which isnt good either
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* list2Tail = list2;
        while (list2Tail->next) {
            list2Tail = list2Tail->next;
        }
        int count = 0;
        ListNode* temp = list1;
        while (count != a-1) {
            ++count;
            temp = temp->next;
        }
        ListNode* list1Prev = temp;
        temp = temp->next;
        list1Prev ->next = list2;
        ++count;
        ListNode* prev;
        while (count <= b) {
            prev = temp;
            temp = temp->next;
            // free might cause UB 
            // (compiler shows alloc dealloc mismatch operator new vs free, changed it to delete)
            delete(prev); 
            ++count;
        }
        list2Tail->next = temp;
        return list1;
    }
};