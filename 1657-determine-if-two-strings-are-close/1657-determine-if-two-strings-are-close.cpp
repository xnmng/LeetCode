// https://leetcode.com/problems/determine-if-two-strings-are-close/discuss/935920/C++-Short-and-Simple-oror-O(-N-)-solution
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> v1(26);
        vector<int> v2(26);
        for (auto i : word1) {
            ++v1[i - 'a'];
        }
        for (auto i : word2) {
            ++v2[i - 'a'];
            if (v1[i - 'a'] == 0) return false;
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        return v1 == v2;
    }
};