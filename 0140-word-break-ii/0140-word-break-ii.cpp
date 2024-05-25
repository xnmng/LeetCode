class Solution {
private:
    void dfs(string& s, int index, unordered_set<string>& set, 
             vector<string>& path, vector<string>& ans) {
        if (index == s.size()) {
            string sentence{path[0]};
            for (auto i = 1; i < path.size(); ++i) {
                sentence += " " + path[i];
            }
            ans.emplace_back(move(sentence));
            return;
        }
        for (auto i = index; i <= s.size(); ++i) {
            if (set.find(s.substr(index, i - index)) != set.end()) {
                // cout << "match: " << s.substr(index, i - index) << " " 
                    // << index << " " << i << "\n";
                path.emplace_back(s.substr(index, i - index));
                dfs(s, i, set, path, ans);
                path.pop_back();
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        for (auto i : wordDict) set.insert(i);
        vector<string> ans;
        vector<string> path;
        dfs(s, 0, set, path, ans);
        return ans;
    }
};