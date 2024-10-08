// notice that for the trie, you dont actually need to store the val of each node! (you can if you want)
class Trie {
    vector<Trie*> next;
    bool isWord;
public:
    Trie() : next(vector<Trie*>(26, nullptr)), isWord(false) {}
    
    void insert(string word) {
        auto index{1};
        if (next[word[0] - 'a'] == nullptr) {
            next[word[0] - 'a'] = new Trie();
        }
        Trie* cur{next[word[0] - 'a']};
        while (index < word.size()) {
            if (cur->next[word[index] - 'a'] == nullptr) {
                cur->next[word[index] - 'a'] = new Trie();
            }
            cur = cur->next[word[index] - 'a'];
            ++index;
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        auto index{1};
        auto cur{next[word[0] - 'a']};
        while (index < word.size()) {
            if (cur == nullptr) return false;
            cur = cur->next[word[index] - 'a'];
            ++index;
        }
        if (cur == nullptr) return false;
        return cur->isWord;
    }
    
    bool startsWith(string prefix) {
        auto index{1};
        auto cur{next[prefix[0] - 'a']};
        while (index < prefix.size()) {
            if (cur == nullptr) return false;
            cur = cur->next[prefix[index] - 'a'];
            ++index;
        }
        return cur != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

// ["Trie","search"]
// [[],["a"]]