class Solution {
public:
    int lengthOfLastWord(string s) {
        int index = s.size()-1;
        int ans = 0;
        while (s[index] == ' ') --index;
        while (index >= 0 && s[index] != ' ') {
            ++ans;
            --index;
        }
        return ans;
    }
};