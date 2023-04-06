// https://youtu.be/AeHMvcKuR0Y
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        auto sum{0.0};
        auto ans{INT_MIN * 1.0};
        for (auto i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            ans = max(ans, ceil(sum / (i+1)));
        }
        return ans;
    }
};