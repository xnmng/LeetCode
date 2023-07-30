class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> count(3, 0); // [5, 10, 20]
        for (auto i : bills) {
            if (i == 5) ++count[0];
            else if (i == 10) {
                if (count[0] == 0) return false;
                --count[0];
                ++count[1];
            }
            else if (i == 20) {
                if (count[0] >= 1 && count[1] >= 1) {
                    --count[0];
                    --count[1];
                } else if (count[0] >= 3) {
                    count[0] -= 3;
                } else return false;
            }
        }
        return true;
    }
};