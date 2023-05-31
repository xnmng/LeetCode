class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        auto ans{0};
        auto prev{0};
        for (auto i : target) {
            if (i > prev) {
                ans += i - prev;
            }
            prev = i;
        }
        return ans;
    }
};