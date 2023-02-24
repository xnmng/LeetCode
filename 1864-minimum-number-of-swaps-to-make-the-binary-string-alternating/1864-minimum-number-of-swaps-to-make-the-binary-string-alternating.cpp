class Solution {
public:
    int minSwaps(string s) {
        auto zero{0};
        auto one{0};
        auto ans1{0}; // 1010...
        auto ans2{0}; // 0101...
        auto index{0};
        for (auto i : s) {
            if (i == '0') ++zero;
            else ++one;
            if (index % 2 == 0) {
                if (i == '0') ++ans1;
                else ++ans2;
            }
            else {
                if (i == '0') ++ans2;
                else ++ans1;
            }
            ++index;
        }
        // cout << zero << " " << one << " " << ans1 << " " << ans2 << "\n";
        if (abs(zero - one) > 1) return -1;
        if (zero == one) return min(ans1, ans2) / 2;
        if (zero > one) return ans2 / 2;
        return ans1 / 2;
    }
};

// "100"