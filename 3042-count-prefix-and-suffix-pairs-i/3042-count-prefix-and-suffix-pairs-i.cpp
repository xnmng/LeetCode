class Solution {
public:
    // could probably use a trie, but brute force will pass these constraints
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                ans += helper(words[i], words[j]);
            }
        }
        return ans;
    }

    bool helper(string& a, string& b) {
        int m = a.size();
        int n = b.size();
        if (m > n) return false;
        cout << a << " " << b << "\n";
        for (int i = 0; i < m; ++i) {
            if (a[i] != b[i]) {
                // cout << i << " first\n";
                return false;
            }
            if (a[m-1-i] != b[n-1-i]) {
                // cout << i << " second\n";
                return false;
            }
        }
        return true;
    }
};