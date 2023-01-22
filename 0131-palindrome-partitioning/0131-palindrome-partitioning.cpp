class Solution {
private:
    void dfs(string& s, vector<string>& path, vector<vector<string>>& ans, int start = 0) {
        if (start == s.size()) {
            ans.push_back(path);
            return;
        }
        for (auto i = start; i < s.size(); ++i) {
            if (isPalindrome(s, start, i)) {
                path.push_back(s.substr(start, i - start + 1));
                dfs(s, path, ans, i+1);
                path.pop_back();
            }
        }
    }
    
    bool isPalindrome(string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            ++start;
            --end;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        dfs(s, path, ans);
        return ans;
    }
};