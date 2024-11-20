class Solution {
public:
    int takeCharacters(string s, int k) {
        // test edge cases where we cannot take chars at all
        if (k == 0) return 0;
        if (s.size() < 3 * k) return -1;
        vector<int> v(3, 0);
        for (char c : s) {
            ++v[c - 'a'];
        }
        for (int i = 0; i < 3; ++i) {
            if (v[i] < k) return -1;
        }

        // assume we take the entire right part of the string until we hit requirement, 
        // then try to improve this using sliding window
        int n = s.size();
        for (int i = 0; i < 3; ++i) {
            v[i] = 0;
        }
        int left = 0;
        int right = n-1;
        while (v[0] < k || v[1] < k || v[2] < k) {
            ++v[s[right] - 'a'];
            --right;
        }
        ++right;
        int ans = v[0] + v[1] + v[2];
        while (right < n) {
            ++v[s[left] - 'a'];
            ++left;
            while (v[0] >= k && v[1] >= k && v[2] >= k) {
                // cout << left << " " << right << "\n";
                // cout << s.substr(0, left) << " " << s.substr(right) << "\n";
                ans = min(ans, v[0] + v[1] + v[2]);
                if (right == n) break;
                --v[s[right] - 'a'];
                ++right;
            }
        }
        return ans;
    }
};
// "caaa"
// 1
// "aabbccca"
// 2