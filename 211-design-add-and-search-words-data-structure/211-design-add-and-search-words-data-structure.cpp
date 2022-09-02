// hashmap solution (for searching words) is essentially brute force (will TLE for large test cases)

class WordDictionary {
    WordDictionary* arr[26]{};
    bool isWord;
public:
    WordDictionary() : isWord(false) {}
    
    void addWord(string word) {
        auto index{0};
        auto cur{this};
        while (index < word.size()) {
            if (cur->arr[word[index] - 'a'] == nullptr) {
                cur->arr[word[index] - 'a'] = new WordDictionary();
            }
            cur = cur->arr[word[index] - 'a'];            
            ++index;
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        return find(word, 0, this);
    }
private: 
    bool find(string word, int index, WordDictionary* cur) {
        while (index < word.size()) {
            if (word[index] == '.') {
                for (auto i = 0; i < 26; ++i) {
                    if (cur->arr[i]
                        && find(word, index+1, cur->arr[i])) return true;
                }
                return false;
            }
            else if (!cur->arr[word[index] - 'a']) return false;
            cur = cur->arr[word[index]- 'a'];            
            ++index;
        }
        
        return cur->isWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

// ["WordDictionary","addWord","addWord","addWord","addWord","search","search","addWord","search","search","search","search","search","search"]
// [[],["at"],["and"],["an"],["add"],["a"],[".at"],["bat"],[".at"],["an."],["a.d."],["b."],["a.d"],["."]]