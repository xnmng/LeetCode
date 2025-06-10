class Solution {
public:
    int maxDifference(string s) {
        vector<int> v(26, 0);
        for (char c : s) {
            ++v[c - 'a'];
        }
        int oddMax = 0;
        int evenMin = INT_MAX;
        for (int i = 0; i < 26; ++i) {
            if (v[i] == 0) continue;
            if (v[i] % 2 == 1) oddMax = max(oddMax, v[i]);
            else evenMin = min(evenMin, v[i]);
        }
        // cout << oddMax << " " << evenMin << "\n";
        return oddMax - evenMin;
    }
};