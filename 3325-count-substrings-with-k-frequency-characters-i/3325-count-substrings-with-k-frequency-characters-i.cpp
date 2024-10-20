class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int ans = 0;
        int n = s.size();
        int left = 0;
        int right = 0;
        vector<int> count(26, 0);
        while (right < n) {
            ++count[s[right] - 'a'];
            while (count[s[right] - 'a'] == k) {
                ans += n - right;
                --count[s[left] - 'a'];
                ++left;
            }
            ++right;
        }
        return ans;
    }
};