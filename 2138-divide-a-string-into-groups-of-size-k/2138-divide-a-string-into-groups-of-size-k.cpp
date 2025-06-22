class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n = s.size();
        if (n % k != 0) {
            s += string(k - (n % k), fill);
        }
        n = s.size();
        // cout << s << "\n";
        for (int i = 0; i + k <= n; i += k) {
            // cout << s.substr(i, k) << "\n";
            ans.emplace_back(s.substr(i, k));
        }
        return ans;
    }
};