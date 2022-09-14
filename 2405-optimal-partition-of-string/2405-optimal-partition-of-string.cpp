class Solution {
public:
    int partitionString(string s) {
        vector<int> count(26,0);
        auto ans{0};
        for (auto i : s) {
            if (count[i - 'a'] == 1) {
                ++ans;
                for (auto i = 0; i < 26; ++i) {
                    count[i] = 0;
                }
            }
            ++count[i - 'a'];
        }
        return ans+1;
    }
};