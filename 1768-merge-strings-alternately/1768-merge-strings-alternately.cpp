class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        auto index1{0};
        auto index2{0};
        while (index1 < word1.size() && index2 < word2.size()) {
            ans += word1[index1];
            ans += word2[index2];
            ++index1;
            ++index2;
        }
        if (index1 != word1.size()) ans += word1.substr(index1);
        if (index2 != word2.size()) ans += word2.substr(index2);
        return ans;
    }
};