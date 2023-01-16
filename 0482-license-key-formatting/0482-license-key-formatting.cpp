class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans;
        ans.reserve(s.size());
        auto count{0};
        for (auto i = s.rbegin(); i != s.rend(); ++i) {
            if (*i == '-') continue;
            if (count == k) {
                ans.push_back('-');
                count = 0;
            }
            ans.push_back(toupper(*i));
            ++count;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};