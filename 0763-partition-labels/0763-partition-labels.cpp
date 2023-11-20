class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> last;
        int n = s.size();
        for (auto i = 0; i < n; ++i) {
            last[s[i]] = i;
        }
        vector<int> ans;
        int count = 0;
        int prev = 0;
        for (auto i = 0; i < n; ++i) {
            // early return condition
            if (count == n-1) {
                ans.emplace_back(n - prev);
                break;
            }
            count = max(count, last[s[i]]);
            if (i == count) {
                ans.emplace_back(i - prev + 1);
                prev = count + 1;
            }
        }
        return ans;
    }
};
// "eaaaabaaec"
