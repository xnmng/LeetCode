class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        dfs(s, ans);
        return ans;
    }
    
    void dfs(string& s, vector<string>& ans, int index = 0) {
        if (index == s.size()) ans.emplace_back(s);
        else if (!isalpha(s[index])) dfs(s, ans, index + 1);
        else {
            char cur = s[index];
            if (isupper(s[index])) {
                s[index] = tolower(s[index]);
                dfs(s, ans, index + 1);
            } else {
                s[index] = toupper(s[index]);
                dfs(s, ans, index + 1);
            }            
            s[index] = cur;
            dfs(s, ans, index + 1);
        }
    }
};