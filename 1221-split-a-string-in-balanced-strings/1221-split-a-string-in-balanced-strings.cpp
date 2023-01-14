class Solution {
public:
    int balancedStringSplit(string s) {
        auto ans{0};
        auto count{0};
        for (auto i : s) {
            if (i == 'R') ++count;
            else --count;
            if (count == 0) ++ans;
        }
        return ans;
    }
};