class Solution {
public:
    vector<string> stringSequence(string target) {
        string cur = "";
        vector<string> ans;
        for (char c : target) {
            cur += 'a';
            ans.emplace_back(cur);
            while (c != cur.back()) {
                cur.back() += 1;
                ans.emplace_back(cur);
            }
        }
        return ans;
    }
};