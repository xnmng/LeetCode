class Solution {
private:
    void dfs(char cur, vector<vector<int>>& adjList, char& smallest, vector<int>& v) {
        if (v[cur - 'a'] != -1) return;
        v[cur - 'a'] = smallest; // prevent infinite loop
        for (auto i : adjList[cur - 'a']) {
            if ('a' + i < smallest) smallest = 'a' + i;
            dfs(i + 'a', adjList, smallest, v);
        }
        v[cur - 'a'] = smallest;
    }
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> v(26, -1);
        vector<vector<int>> adjList(26);
        for (auto i = 0; i < s1.size(); ++i) {
            adjList[s1[i] - 'a'].push_back(s2[i] - 'a');
            adjList[s2[i] - 'a'].push_back(s1[i] - 'a');
        }
        char smallest;
        for (auto i = 0; i < 26; ++i) {
            smallest = 'a' + i;
            dfs('a' + i, adjList, smallest, v);
        }
        for (auto& i : baseStr) {
            i = v[i - 'a'];
        }
        return baseStr;
    }
};