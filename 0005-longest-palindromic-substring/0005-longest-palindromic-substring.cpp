// https://leetcode.com/problems/longest-palindromic-substring/solution/
class Solution {
    pair<int,int> helper(string& s, int left, int right) {
        int n = s.size();
        while (left >= 0 && right < n && s[left] == s[right]) {
            --left;
            ++right;
        }
        ++left;
        --right;
        if (right-left <= 0) return {left, 1};
        // cout << left << " " << right-left+1 << " " 
        //     << s.substr(left, right-left+1) << "\n";
        return {left, right-left+1};
    }
public:
    // todo: Manacher's algorithm O(n) time O(n) space
    
    // set center and expand (O(n^2) time, O(1) space)
    string longestPalindrome(string s) {
        pair<int,int> ans{0,1}; // <index, length>
        int n = s.size();
        for (auto i = 0; i < n; ++i) {
            if (i > 0 && s[i] == s[i-1]) {
                auto [index, length] = helper(s, i-1, i);
                if (length > ans.second) {
                    ans.first = index;
                    ans.second = length;
                }
            }
            auto [index, length] = helper(s, i-1, i+1);
            if (length > ans.second) {
                ans.first = index;
                ans.second = length;
            }
        }
        return s.substr(ans.first, ans.second);
    }
};