class Solution {
public:
    int minLength(string s) {
        string ans;
        for (char c : s) {
            if (c == 'B' && !ans.empty() && ans.back() == 'A') ans.pop_back();
            else if (c == 'D' && !ans.empty() && ans.back() == 'C') ans.pop_back();
            else ans += c;
        }
        return ans.size();
    }
};