class Solution {
public:
    // the longest palindrome we have is to take pairs of elements and (if applicable) 1 odd char
    // O(n) time, O(1) space
    int longestPalindrome(string s) {
        vector<bool> v(256, 0);
        int ans = 0;
        int count = 0; // store number of true inside vector v
        
        for (char c : s) {
            if (v[c]) {
                ans += 2;
                count -= 2; // to cancel out the ++count below since we are removing 1
            }
            ++count;
            v[c] = v[c] ^ true;
        }
        
        return ans + (count > 0 ? 1 : 0);
    }

    
//     // using ump to count frequencies (O(k) space; k is number of unique chars)
//     int longestPalindrome(string s) {
//         unordered_map<char,int> mp;
//         for (char c : s) {
//             ++mp[c];
//         }
//         bool hasOdd{false};
//         int ans{0};
//         for (auto& [k, v] : mp) {
//             ans += v/2 * 2;
//             if (v % 2 == 1) hasOdd = true;
//         }
//         return ans + (hasOdd ? 1 : 0);
//     }
};