class Solution {
public:
    // if we want to make the smallest string, remove the rightmost smallest non-'*' char
    // O(nlogn) time, O(n) space
    string clearStars(string s) {
        // pq should put smallest char largest index at root
        auto comp = [](pair<int, char> a, pair<int,char> b) {
            if (a.second == b.second) return a.first < b.first;
            return a.second > b.second;
        };
        priority_queue<pair<int,char>, vector<pair<int,char>>, decltype(comp)> pq(comp);
        int n = s.size();
        unordered_set<int> remove;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                auto [index, _] = pq.top();
                // cout << index << "\n";
                pq.pop();
                remove.insert(index);
            }
            else pq.emplace(i, s[i]);
        }
        string ans = "";
        ans.reserve(n);
        for (int i = 0; i < n; ++i) {
            if (remove.find(i) != remove.end() || s[i] == '*') continue;
            ans += s[i];
        }
        return ans;
    }
};