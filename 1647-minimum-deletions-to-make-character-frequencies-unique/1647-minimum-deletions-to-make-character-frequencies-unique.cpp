class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26, 0);
        for (char i : s) {
            ++v[i - 'a'];
        }
        sort(v.begin(), v.end());
        int ans{0};
        for (int i = 24; i >= 0; --i) {
            if (v[i] == 0) break;
            // change v[i] to (v[i+1] - 1) or 0, whichever larger
            if (v[i] >= v[i+1]) {
                ans += min(v[i], v[i] - v[i+1] + 1);
                v[i] = max(0, v[i+1] - 1);
            }
        }
        return ans;
    }
};

