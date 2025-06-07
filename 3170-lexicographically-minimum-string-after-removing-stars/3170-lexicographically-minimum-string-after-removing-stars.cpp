class Solution {
public:
    string clearStars(string s) {
        string ans;
        int n = s.size();
        vector<vector<int>> v(26);
        vector<bool> valid(n, true);
        int smallest = 25;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                // cout << i << " " << v[smallest].back() << "\n";
                valid[i] = false;
                valid[v[smallest].back()] = false;
                v[smallest].pop_back();
                smallest = 0;
                while (smallest < 26 && v[smallest].empty()) ++smallest;
                // if (smallest == -1) smallest = 25;
                // cout << "smallest at index " << smallest << "\n";
            }
            else {
                v[s[i] - 'a'].emplace_back(i);
                smallest = min(smallest, s[i] - 'a');
                // cout << "added " << i << " " << s[i] - 'a' << "\n";
            }
        }
        // cout << "here\n";
        for (int i = 0; i < n; ++i) {
            if (valid[i]) ans += s[i];
        }
        return ans;
    }
};

// class Solution {
// public:
//     // if we want to make the smallest string, remove the rightmost smallest non-'*' char
//     // O(nlogn) time, O(n) space
//     string clearStars(string s) {
//         // pq should put smallest char largest index at root
//         auto comp = [](pair<int, char> a, pair<int,char> b) {
//             if (a.second == b.second) return a.first < b.first;
//             return a.second > b.second;
//         };
//         priority_queue<pair<int,char>, vector<pair<int,char>>, decltype(comp)> pq(comp);
//         int n = s.size();
//         unordered_set<int> remove;
//         for (int i = 0; i < n; ++i) {
//             if (s[i] == '*') {
//                 auto [index, _] = pq.top();
//                 // cout << index << "\n";
//                 pq.pop();
//                 remove.insert(index);
//             }
//             else pq.emplace(i, s[i]);
//         }
//         string ans = "";
//         ans.reserve(n);
//         for (int i = 0; i < n; ++i) {
//             if (remove.find(i) != remove.end() || s[i] == '*') continue;
//             ans += s[i];
//         }
//         return ans;
//     }
// };