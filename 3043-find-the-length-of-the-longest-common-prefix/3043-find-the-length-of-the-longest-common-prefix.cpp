
class Solution {

public:
    // brute force will probably TLE
    // to optimize, can use a trie to compare 1 number with all of the other arr
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Node* dummy = new Node(' ');
        Node* ptr;
        for (int i : arr1) {
            string num = to_string(i);
            ptr = dummy;
            for (char c : num) {
                if (!ptr->next[c - '0']) {
                    ptr->next[c - '0'] = new Node(c);
                }
                ptr = ptr->next[c - '0'];
            }
        }
        int ans = 0;
        int count;
        for (int i : arr2) {
            string num = to_string(i);
            count = 0;
            ptr = dummy;
            for (char c : num) {
                ptr = ptr->next[c - '0'];
                if (!ptr) break;
                ++count;
            }
            ans = max(ans, count);
        }
        return ans;
    }
    
    struct Node {
        char val;
        vector<Node*> next;
        Node(int val) : val(val), next(10, nullptr) {};
    };

};