class Solution {
private:
    bool isPrefix(string& s, string& t) {
        if (s.size() > t.size()) return false;
        for (auto i = 0; i < s.size(); ++i) if (s[i] != t[i]) return false;
        return true;
    }
public:
    int countPrefixes(vector<string>& words, string s) {
        auto ans{0};
        for (auto& i : words) {
            if (isPrefix(i, s)) ++ans;
        }
        return ans;
    }
};