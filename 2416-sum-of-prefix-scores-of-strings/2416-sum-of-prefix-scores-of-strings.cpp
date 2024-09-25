class Solution {
public:
    // use a trie to store the strings and each char frequency
    // iterate throug again to compute the score for a given string
    // O(nk) time 2 pass, O(nk) space
    // where n is the number of words and k is the number of chars for each word
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> ans;
        ans.reserve(words.size());
        Node* root = new Node();
        Node* cur;
        for (auto& i : words) {
            cur = root;
            for (char c : i) {
                if (cur->next[c - 'a'] == nullptr) {
                    cur->next[c - 'a'] = new Node();
                }
                ++cur->next[c - 'a']->freq;
                cur = cur->next[c - 'a'];
            }            
        }

        for (auto& i : words) {
            cur = root;
            int count = 0;
            int index = 0;
            for (char c : i) {
                // when counting, if we enounter 1 as the freq, 
                // we know theres only 1 word with this value, 
                // can calculate and return early
                if (cur->next[c - 'a']->freq == 1) {
                    count -= index;
                    count += i.size();
                    break;
                }
                count += cur->next[c - 'a']->freq;
                cur = cur->next[c - 'a'];
                ++index;
            }
            ans.emplace_back(count);
        }
        return ans;
    }
    
    // DO NOT USE VECTOR! (MLE!)
    // since we know beforehand the size, just use a c-style array!
    struct Node {
        int freq;
        Node* next[26];
        Node() : freq(0), next(nullptr) {}
        
        ~Node() {
            for (auto& child : next) {
                delete child;  // Recursively delete child nodes
            }
        }
    };

    void deleteTrie(Node* node) {
        if (node) {
            for (auto& child : node->next) {
                deleteTrie(child);
            }
            delete node;
        }
    }
};