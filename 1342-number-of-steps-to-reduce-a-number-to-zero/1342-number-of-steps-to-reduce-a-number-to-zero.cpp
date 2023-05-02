class Solution {
public:
    int numberOfSteps(int num) {
        auto ans{0};
        while (num != 0) {
            if (num % 2 == 1) --num;
            else num /= 2;
            ++ans;
        }
        return ans;
    }
};