class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans;
        ans.reserve(queries.size());
        vector<int> v;
        v.reserve(words.size());
        for (auto& i : words) {
            if (isvowel(*i.begin()) && isvowel(*i.rbegin())) {
                v.emplace_back(v.empty() ? 1 : 1 + v.back());
            } else v.emplace_back(v.empty() ? 0 : v.back());
        }
        for (auto& i : queries) {
            if (i[0] == 0) ans.emplace_back(v[i[1]]);
            else ans.emplace_back(v[i[1]] - v[i[0] - 1]);
        }
        return ans;
    }

    bool isvowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};