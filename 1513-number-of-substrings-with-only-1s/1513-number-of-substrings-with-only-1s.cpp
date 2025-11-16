class Solution {
public:
    int numSub(string s) {
        auto modulo{static_cast<int>(1e9 + 7)};
        auto ans{0l};
        auto count{0l};
        for (auto i : s) {
            if (i == '1') ++count;
            else count = 0;
            ans = (ans + count) % modulo;
        }
        return ans;
    }
};