class Solution {
public:
    // count the frequencies, follow the order, 
    // then add the remaining chars (since it can be in any order)
    string customSortString(string order, string s) {
        vector<int> v(26, 0);
        for (char c : s) {
            ++v[c - 'a'];
        }
        string ans;
        ans.reserve(s.size());
        for (char c : order) {
            ans += string(v[c - 'a'], c);
            v[c - 'a'] = 0;
        }
        for (int i = 0; i < 26; ++i) {
            ans += string(v[i], 'a' + i);
        }
        return ans;
    }
};