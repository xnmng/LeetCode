class Solution {
public:
    // keep track of last char seen index, update it accordingly
    
    // 2 pointer approach
    int lengthOfLongestSubstring(string s) {
        vector<bool> v(256, false);
        int left = 0;
        int right = 0;
        int count = 0;
        int ans = 0;
        while (right < s.size()) {
            if (v[s[right]]) {
                while (left < right && v[s[right]]) {
                    v[s[left]] = false;
                    --count;
                    ++left;
                }
            } 
            v[s[right]] = true;
            ++count;
            ans = max(ans, count);
            ++right;
                
            // cout << left << " " << right << " " << ans << " " << count << "\n";
        }
        return ans;
    }
};