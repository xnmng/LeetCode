class Solution {
private:
    void dfs(string& digits, unordered_map<char, vector<char>>& mp, 
             int index, string& cur, vector<string>& ans) {
        if (index == digits.size() && !cur.empty()) {
            ans.push_back(cur);
            return;
        }
        
        for (auto& i : mp[digits[index]]) {
            // cout << i << "\n";
            cur += i;
            dfs(digits, mp, index+1, cur, ans);
            cur.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, vector<char>> mp{
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}}
        };
        
        vector<string> ans;
        string cur{""};
        dfs(digits, mp, 0, cur, ans);
        return ans;
    }
};