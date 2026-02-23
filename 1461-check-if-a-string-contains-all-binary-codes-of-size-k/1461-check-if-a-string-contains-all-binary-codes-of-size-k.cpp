class Solution {
public:
    bool hasAllCodes(string s, int k) {
        // unordered_set<int> set;
        int count = 0;
        int offset = pow(2, k);
        vector<bool> set(offset, false);
        int cur = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            cur *= 2;
            cur += s[i] - '0';
            if (i >= k-1) {
                if (cur >= offset) cur -= offset; // remove largest bit if it is set
                // set.insert(cur);
                if (!set[cur]) {
                    ++count;
                    set[cur] = true;
                }
            }
        }
        // return set.size() == offset; // reuse offset as expected count
        return count == offset; // reuse offset as expected count
    }
};