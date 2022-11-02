class Solution {
private:
    bool isMutation(string& a, string& b) {
        auto count{0};
        for (auto i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) ++count;
        }
        return count <= 1;
    }
    
public:
    int minMutation(string start, string end, vector<string>& bank) {
        auto n{bank.size()};
        vector<vector<int>> adjlist(n, vector<int>(n, 0));
        for (auto i = 0; i < n; ++i) {
            for (auto j = i+1; j < n; ++j) {
                if (isMutation(bank[i], bank[j])) {
                    adjlist[i][j] = 1;
                    adjlist[j][i] = 1;
                }
            }
        }
        unordered_map<string, int> mp;
        for (auto i = 0; i < n; ++i) {
            mp[bank[i]] = i;
        }
        unordered_set<string> s;
        queue<string> q;
        for (auto& i : bank) {
            if (isMutation(i, start)) q.push(i);
        }
        auto count{1};
        string cur;
        
        while (!q.empty()) {
            queue<string> next;
            while (!q.empty()) {
                cur = q.front();
                q.pop();
                if (s.find(cur) != s.end()) continue;
                if (cur == end) return count;
                s.insert(cur);
                for (auto i = 0; i < n; ++i) {
                    if (adjlist[mp[cur]][i] == 1) next.push(bank[i]);
                }
            }
            q = next;
            ++count;
        }
        return -1;
    }
};