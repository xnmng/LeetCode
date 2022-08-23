class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> diff;
        for (auto i = 0; i < s1.size(); ++i) {
            if (s1[i] == s2[i]) continue;
            diff.push_back(i);
        }
        if (diff.size() == 0) return true;
        if (diff.size() != 2) return false;
        return s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]]; 
    }
};