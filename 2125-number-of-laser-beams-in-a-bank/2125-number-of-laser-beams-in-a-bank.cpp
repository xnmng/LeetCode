class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        auto ans{0};
        auto prev{0};
        auto cur{0};
        for (auto& i : bank) {
            cur = 0;
            for (auto& j : i) {
                if (j == '1') ++cur;
            }
            if (cur > 0) {
                ans += cur * prev;
                prev = cur;
            }
        }
        return ans;
    }
};