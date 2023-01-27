// https://leetcode.com/problems/concatenated-words/discuss/95677/C++-772-ms-dp-solution
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        unordered_set<string> dict(words.begin(), words.end());
        for(auto w : words) {
            if(w.empty())
                continue;
            vector<int> dp(w.size() + 1, 0);
            dp[0] = 1;
            for(int i = 1 ; i <= w.size() ;  i++) {
                for(int j = 0 ; j < i ; j++) {
                    if(i - j < w.size() && dp[j] == 1 && dict.find(w.substr(j, i - j)) != dict.end()) {
                        dp[i] = 1;
                        break;
                    }
                }
            }
            if(dp[w.size()])
                res.push_back(w);
        }
        return res;
    } 
};