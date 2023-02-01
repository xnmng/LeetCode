class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxi{INT_MIN};
        int mini{INT_MAX};
        for (auto i : nums) {
            mini = min(i, mini);
            maxi = max(i, maxi);
        }
        return gcd(mini, maxi);
    }
};