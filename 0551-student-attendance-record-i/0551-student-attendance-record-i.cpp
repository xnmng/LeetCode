class Solution {
public:
    bool checkRecord(string s) {
        auto acount{0};
        auto lcount{0};
        for (auto& i : s) {
            if (acount >= 2 || lcount >= 3) return false;
            if (i == 'L') {
                ++lcount;
            }
            else {
                lcount = 0;
                if (i == 'A') ++acount;
            }
            
        }
        return acount < 2 && lcount < 3;
    }
};