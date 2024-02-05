class Solution {
public:
    // could also store counts, iterate across string again, if count is 1 return that index (2 O(n) passes)
    //
    // this solution is O(n) 1 pass + O(26) 1 pass
    int firstUniqChar(string s) {
        vector<int> firstIndex(26, INT_MAX);
        for (auto i = 0; i < s.size(); ++i) {
            if (firstIndex[s[i] - 'a'] == INT_MAX) {
                firstIndex[s[i] - 'a'] = i;                
            } 
            else if (firstIndex[s[i] - 'a'] >= 0) {
                firstIndex[s[i] - 'a'] = -1;
            }
        }
        auto ans{INT_MAX};
        for (auto i : firstIndex) {
            if (i == -1) continue;
            ans = min(i, ans);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};