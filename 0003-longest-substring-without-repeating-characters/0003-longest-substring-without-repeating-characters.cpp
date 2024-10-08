class Solution {
public:
    // keep track of last char seen index, update it accordingly
    // at each index, calculate the longest substring with s[i] as the end
    int lengthOfLongestSubstring(string s) {
        vector<int> v(256, -1);
        int left = -1;
        int right = 0;
        int ans = 0;
        while (right < s.size()) {
            // when there was already a prev char seen (nifty trick)
            if (v[s[right]] > left) left = v[s[right]];
            v[s[right]] = right;
            ans = max(ans, right - left);
            ++right;
        }
        return ans;
    }
    
//     // 2 pointer approach
//     int lengthOfLongestSubstring(string s) {
//         vector<bool> v(256, false);
//         int left = 0;
//         int right = 0;
//         int count = 0;
//         int ans = 0;
//         while (right < s.size()) {
//             if (v[s[right]]) {
//                 while (left < right && v[s[right]]) {
//                     v[s[left]] = false;
//                     --count;
//                     ++left;
//                 }
//             } 
//             v[s[right]] = true;
//             ++count;
//             ans = max(ans, count);
//             ++right;
                
//             // cout << left << " " << right << " " << ans << " " << count << "\n";
//         }
//         return ans;
//     }
};

// " "
// "abba"