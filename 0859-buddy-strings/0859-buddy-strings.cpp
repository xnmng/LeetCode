class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) return false;
        int diff; // indexes at which char's in s and goal are different
        vector<int> count(26, 0); // track frequency of each char
        vector<int> hasDiff(26, 0);
        for (auto i = 0; i < s.size(); ++i) {
            if (s[i] != goal[i]) ++diff;
            ++count[s[i] - 'a'];
            ++hasDiff[s[i] - 'a'];
            --hasDiff[goal[i] - 'a'];
        }
        for (auto i : hasDiff) {
            if (i != 0) return false;
        }
        if (diff == 2) return true;
        if (diff == 0) {
            for (auto& i : count) {
                if (i >= 2) return true;
            }            
        }
        return false;
    }
};

// "abcaa"
// "abcbb"