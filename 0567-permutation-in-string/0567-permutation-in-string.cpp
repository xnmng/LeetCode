class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        
        vector<int> s1c(26, 0);
        vector<int> s2c(26, 0);
        for (auto i = 0; i < s1.size(); ++i) {
            ++s1c[s1[i] - 'a'];
            ++s2c[s2[i] - 'a'];
        }
        auto count{0};
        for (auto i = 0; i < 26; ++i) {
            if (s1c[i] == s2c[i]) ++count;
        }
        for (auto i = s1.size(); i < s2.size(); ++i) {
            if (count == 26) return true;
            
            --s2c[s2[i - s1.size()] - 'a'];
            if (s2c[s2[i - s1.size()] - 'a'] == s1c[s2[i - s1.size()] - 'a']) ++count;
            else if (s2c[s2[i - s1.size()] - 'a'] + 1 == s1c[s2[i - s1.size()] - 'a']) --count;
            
            ++s2c[s2[i] - 'a'];
            if (s2c[s2[i] - 'a'] == s1c[s2[i] - 'a']) ++count;
            else if (s2c[s2[i] - 'a'] - 1 == s1c[s2[i] - 'a']) --count;
        }
        return count == 26;
    }
};

// "abc"
// "bbbca"
// "trinitrophenylmethylnitramine"
// "dinitrophenylhydrazinetrinitrophenylmethylnitramine"