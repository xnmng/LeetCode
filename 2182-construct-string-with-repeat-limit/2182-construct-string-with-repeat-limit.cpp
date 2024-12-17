class Solution {
public:
    // probably a more elegant way to write this...
    string repeatLimitedString(string s, int repeatLimit) {
        string ans = "";
        ans.reserve(s.size());
        vector<int> v(26, 0);
        for (char c : s) {
            ++v[c - 'a'];
        }
        char prev = ' ';
        int count = 0;
        int distinct;
        bool added;
        while (ans.size() != s.size()) {
            distinct = 0;
            added = false;
            for (int i = 25; i >= 0; --i) {
                if (v[i] == 0) continue;
                else ++distinct;
                if (i + 'a' == prev) {
                    if (count == repeatLimit) continue;
                    ans += i + 'a';
                    --v[i];
                    ++count;
                    // cout << "add " << (char)(i + 'a') << " " << count << "\n";
                    added = true;
                    break;
                }
                else {
                    ans += i + 'a';
                    count = 1;
                    prev = i + 'a';
                    // cout << "add " << (char)(i + 'a') << " " << count << "\n";
                    --v[i];
                    added = true;
                    break;
                }
            }
            if (distinct == 1 && !added) break;
        }
        return ans;
    }
};