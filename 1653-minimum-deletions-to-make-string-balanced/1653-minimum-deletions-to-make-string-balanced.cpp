class Solution {
public:
    // preprocess and suppose each index is the 'pivot' point
    // i.e. < this index, 'a' and > this index, 'b'
    // then calculate the cost to make this requirement
    int minimumDeletions(string s) {
        int n = s.size();
        // aCount[i] := number of a's from [s[i], ..., s[n-1]]
        vector<int> aCount(n, 0);
        for (int i = n-1; i >= 0; --i) {
            if (s[i] == 'a') ++aCount[i];
            if (i < n-1) aCount[i] += aCount[i+1];
        }
        if (aCount[0] == 0 || aCount[0] == n) return 0;
        int ans = INT_MAX;
        // bCount := number of b's excluding ith index
        int bCount = 0;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, bCount + aCount[i]);
            if (s[i] == 'b') ++bCount;
        }
        // our loop does not consider a string of all b's
        ans = min(ans, bCount);
        return ans;
    }
};
// "a"
// "aaaaaaaaaaaaaa"
// "aabbbbaabababbbbaaaaaabbababaaabaabaabbbabbbbabbabbababaabaababbbbaaaaabbabbabaaaabbbabaaaabbaaabbbaabbaaaaabaa"