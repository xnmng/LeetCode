class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> s;
        unordered_set<int> v;
        auto n{fronts.size()};
        for (auto i = 0; i < n; ++i) {
            if (fronts[i] == backs[i]) s.insert(fronts[i]);
            else {
                v.insert(fronts[i]);
                v.insert(backs[i]);
            }
        }
        auto ans{INT_MAX};
        for (auto& i : v) {
            if (s.find(i) == s.end()) ans = min(ans, i);
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

// [1,1]
// [1,2]