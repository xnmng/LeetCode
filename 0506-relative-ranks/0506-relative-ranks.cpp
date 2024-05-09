class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> ans(n);
        vector<pair<int,int>> v; // <score, index>
        for (int i = 0; i < n; ++i) {
            v.emplace_back(score[i], i);
        }
        sort(v.rbegin(), v.rend()); // sort in descending order by providing reverse itr's
        ans[v[0].second] = "Gold Medal";
        if (n >= 2) ans[v[1].second] = "Silver Medal";
        if (n >= 3) ans[v[2].second] = "Bronze Medal";
        for (int i = 3; i < n; ++i) {
            // cout << v[i].first << " " << v[i].second << "\n";
            ans[v[i].second] = to_string(i+1);
        }
        return ans;
    }
};
// [1]