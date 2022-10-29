class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> v;
        auto n{growTime.size()};
        v.reserve(n);
        for (auto i = 0; i < n; ++i) {
            v.emplace_back(growTime[i], plantTime[i]);
        }
        sort(v.begin(), v.end(), greater<pair<int,int>>());
        
        auto ans{0};
        auto plant{0};
        for (auto& [g, p] : v) {
            plant += p;
            ans = max(ans, plant + g);
        }
        return ans;
    }
};
// ppppgggg
//     pggg
//      pppgg

