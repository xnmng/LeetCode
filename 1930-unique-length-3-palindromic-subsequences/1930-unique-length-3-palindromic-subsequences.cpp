class Solution {
public:
    // track the first and last occurence of each char
    // all the chars between (first, last) are unique char that can form the middle of the palindrome
    int countPalindromicSubsequence(string s) {
        // aaa -> 0, aba -> 1, ..., zzz -> (26 * 26 - 1)
        int chars = 26;
        vector<int> first(chars, -1);
        vector<int> last(chars, -1);
        int n = s.size();
        int ans = 0;
        for (auto i = 0; i < n; ++i) {
            if (first[s[i] - 'a'] == -1) {
                first[s[i] - 'a'] = i;
            } else {
                last[s[i] - 'a'] = i;
            }
        }
        for (auto i = 0; i < 26; ++i) {
            if (first[i] != -1 && last[i] != -1) {
                vector<bool> v(chars, false);
                int sum = 0;
                for (auto j = first[i]+1; j < last[i]; ++j) {
                    if (!v[s[j] - 'a']) {
                        v[s[j] - 'a'] = true;
                        ++sum;
                        if (sum == 26) break;
                    }
                }
                ans += sum;
            }
        }
        return ans;
    }
};