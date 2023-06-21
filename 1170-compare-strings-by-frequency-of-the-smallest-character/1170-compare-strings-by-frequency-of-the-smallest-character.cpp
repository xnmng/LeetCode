class Solution {
private:
    int helper(string& s) {
        vector<int> v(26, 0);
        for (auto& i : s) ++v[i-'a'];
        for (auto i = 0; i < 26; ++i) {
            if (v[i] > 0) return v[i];
        }
        return -1; // shouldnt happen
    }
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> q;
        vector<int> w;
        vector<int> ans(queries.size(), 0);
        q.reserve(queries.size());
        w.reserve(words.size());
        for (auto& i : queries) {
            q.push_back(helper(i));
        }
        for (auto& i : words) {
            w.push_back(helper(i));
        }
        for (auto i = 0; i < q.size(); ++i) {
            for (auto j = 0; j < w.size(); ++j) {
                if (q[i] < w[j]) ++ans[i];
            }
        }
        return ans;
    }
};

// ["bba","abaaaaaa","aaaaaa","bbabbabaab","aba","aa","baab","bbbbbb","aab","bbabbaabb"]
// ["aaabbb","aab","babbab","babbbb","b","bbbbbbbbab","a","bbbbbbbbbb","baaabbaab","aa"]