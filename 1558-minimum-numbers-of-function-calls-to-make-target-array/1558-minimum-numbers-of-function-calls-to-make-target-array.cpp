class Solution {
private:
    pair<int,int> getSteps(int i) {
        auto inc{0};
        auto mul{0};
        while (i != 0) {
            if (i % 2 == 1) {
                ++inc;
                --i;
            } else {
                ++mul;
                i /= 2;
            }
        }
        return {inc, mul};
    }
public:
    // at each step, either:
    //      increment 1 element
    //      double all elements
    int minOperations(vector<int>& nums) {
        auto ans{0};
        auto count{0}; // maximum number of doubles
        for (auto i : nums) {
            auto [inc, mul] = getSteps(i);
            ans += inc;
            count = max(count, mul);
        }
        ans += count;
        return ans;
    }
};
