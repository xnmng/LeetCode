class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for (char c : s) {
            ++mp[c];
        }
        bool hasOdd{false};
        int ans{0};
        for (auto& [k, v] : mp) {
            ans += v/2 * 2;
            if (v % 2 == 1) hasOdd = true;
        }
        return ans + (hasOdd ? 1 : 0);
    }
};