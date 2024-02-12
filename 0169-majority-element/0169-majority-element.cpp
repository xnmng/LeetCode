class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int ans = 0;
        for (auto i : nums) {
            if (ans == i) ++count;
            else {
                --count;
                if (count < 0) {
                    count = 1;
                    ans = i;
                }
            }
        }
        return ans;
    }
};