class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> v(26, 0);
        for (char c : word) {
            if (isupper(c)) {
                v[c - 'A'] |= 2;
            }
            else if (islower(c)) {
                v[c - 'a'] |= 1;
            }
        }
        int ans = 0;
        for (int i : v) {
            if (i > 2) ++ans;
        }
        return ans;
    }
};