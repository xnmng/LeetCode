class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for (auto& word : words) {
            if (word.size() < pref.size()) continue;
            if (pref == word.substr(0, pref.size())) ++ans;
        }
        return ans;
    }
};