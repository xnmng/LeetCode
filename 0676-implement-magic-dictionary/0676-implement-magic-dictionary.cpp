class MagicDictionary {
private:
    unordered_map<int, vector<string>> mp;
    
    bool match(string& a, string& b) {
        bool ans{true};
        for (auto i = 0; i < a.size(); ++i) {
            if (!ans && a[i] != b[i]) return false;
            else if (a[i] != b[i]) ans = false;
        }
        return !ans;
    }
public:
    MagicDictionary() {}
    
    void buildDict(vector<string> dictionary) {
        for (auto& i : dictionary) {
            mp[i.size()].emplace_back(move(i));    
        }
    }
    
    bool search(string searchWord) {
        for (auto& i : mp[searchWord.size()]) {
            if (match(i, searchWord)) return true;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */