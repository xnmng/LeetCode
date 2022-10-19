class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (auto i : words) ++mp[i];
        vector<pair<string,int>> v;
        for (auto i : mp) {
            v.push_back(i);
        }
        vector<string> ans;
        sort(v.begin(), v.end(), 
            [](pair<string,int> p1, pair<string,int> p2){
                if (p1.second == p2.second) {
                    return p1.first < p2.first;
                } else {
                    return p1.second > p2.second;
                }
            }
        );
        for (auto i = 0; i < k; ++i) {
            ans.push_back(v[i].first);
        }
        return ans;
    }
};