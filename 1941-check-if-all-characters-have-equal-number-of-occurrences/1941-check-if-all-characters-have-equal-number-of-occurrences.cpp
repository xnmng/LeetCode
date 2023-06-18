class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int> v(26, 0);
        for (auto i : s) ++v[i - 'a'];
        auto count{0};
        for (auto i : v) {
            if (i == 0) continue;
            else if (count == 0) count = i;
            else if (count != i) return false;
        }
        return true;
    }
};