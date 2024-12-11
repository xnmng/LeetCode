class Solution {
public:
    int numSplits(string s) {
        unordered_map<char, int> left;
        unordered_map<char, int> right;
        for (char c : s) ++right[c];
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            --right[s[i]];
            if (right[s[i]] == 0) right.erase(s[i]);
            ++left[s[i]];
            if (left.size() > right.size()) break;
            if (left.size() == right.size()) ++ans;
        }
        return ans;
    }
};