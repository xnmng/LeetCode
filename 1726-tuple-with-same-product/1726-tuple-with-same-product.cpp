class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans = 0;
        for (auto i = 0; i < nums.size(); ++i) {
            for (auto j = i+1; j < nums.size(); ++j) {
                // given a combination (a,b,c,d) such that a * b == c * d, 
                // we can permute it a total of 8 ways:
                //      (a,b,c,d)
                //      (a,b,d,c)
                //      (b,a,c,d)
                //      (b,a,d,c)
                //      (c,d,a,b)
                //      (c,d,b,a)
                //      (d,c,a,b)
                //      (d,c,b,a)
                ans += mp[nums[i] * nums[j]] * 8;
                ++mp[nums[i] * nums[j]];
            }
        }
        return ans;
    }
};