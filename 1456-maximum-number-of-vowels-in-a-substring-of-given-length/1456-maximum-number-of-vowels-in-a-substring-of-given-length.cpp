class Solution {
    bool isVowel(char c) {
        return (c == 'a'
        || c == 'e' 
        || c == 'i' 
        || c == 'o' 
        || c == 'u');
    }
public:
    int maxVowels(string s, int k) {
        auto count{0};
        for (auto i = 0; i < s.size() && i < k; ++i) {
            count += isVowel(s[i]);
        }
        auto ans{count};
        auto cur{k};
        while (cur < s.size()) {
            count += isVowel(s[cur]);
            count -= isVowel(s[cur - k]);
            ans = max(count, ans);
            ++cur;
        }
        return ans;
    }
};