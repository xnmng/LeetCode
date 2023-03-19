class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> v(26, 0);
        for (auto i : s) ++v[i - 'a'];
        for (auto i : t) --v[i - 'a'];
        auto ans{0};
        for (auto i : v) ans += abs(i);
        return ans;
    }
};