class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<string> ans;
        ans.reserve(n);
        unordered_map<int,int> mp; // height to index in names
        for (int i = 0; i < n; ++i) {
            mp[heights[i]] = i;
        }
        sort(heights.rbegin(), heights.rend());
        for (int i : heights) {
            ans.emplace_back(names[mp[i]]);
        }
        return ans;
    }
};