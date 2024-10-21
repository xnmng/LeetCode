class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_map<string, int> mp;
        int ans = 0;
        string cur = "";
        dfs(s, cur, mp, ans);
        return ans;
    }
    
    // at each step, add the char and consider both making this a substring and not making it a substring
    void dfs(string& s, string& cur, unordered_map<string,int>& mp, int& ans, int index = 0) {
        if (index == s.size()) return;
        cur += s[index];
        string temp = cur;
        ++mp[cur];
        ans = max(ans, (int) mp.size());
        cur = "";
        dfs(s, cur, mp, ans, index + 1);
        cur = temp;
        --mp[cur];
        if (mp[cur] == 0) mp.erase(cur);
        dfs(s, cur, mp, ans, index + 1);
    }
};