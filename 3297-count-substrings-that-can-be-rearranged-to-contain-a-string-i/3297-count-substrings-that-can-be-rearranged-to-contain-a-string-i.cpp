class Solution {
public:
    // copy paste part 2 answer here
    long long validSubstringCount(string word1, string word2) {
        vector<int> target(26, 0);
        for (char c : word2) {
            ++target[c - 'a'];
        }
        
        int uniqueCount = 0;
        for (int i : target) {
            if (i > 0) ++uniqueCount;
        }
        
        int left = 0;
        int right = 0;
        int n = word1.size();
        
        vector<int> cur(26, 0);
        int curCount = 0;
        
        long long ans = 0;
        
        // 2 pointers
        int l = 0;
        for (int r = 0; r < n; ++r) {
            ++cur[word1[r] - 'a'];
            if (cur[word1[r] - 'a'] == target[word1[r] - 'a']) {
                ++curCount;
            }
            
            while(curCount == uniqueCount && l <= r) {
                ans += n - r;
                
                if (cur[word1[l] - 'a'] == target[word1[l] - 'a']) {
                    --curCount;
                }
                --cur[word1[l] - 'a'];
                ++l;
            }
        }
        
        return ans;
    }
};