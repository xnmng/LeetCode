class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string> s;
        pair<int,int> cur{0,0};
        unordered_map<char, pair<int,int>> mp {
            {'N', {0,1}},
            {'S', {0,-1}},
            {'E', {1,0}},
            {'W', {-1,0}},
        };
        for (auto& i : path) {
            // cout << i << "\n";
            s.insert(to_string(cur.first) + " " + to_string(cur.second));
            cur.first += mp[i].first;
            cur.second += mp[i].second;
            if (s.find(to_string(cur.first) + " " + to_string(cur.second)) != s.end()) return true;
            // cout << i << "\n";
        }
        return false;
    }
};