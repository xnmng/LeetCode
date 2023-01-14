class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        auto n{queries.size()};
        vector<int> ans(n);
        sort(nums.begin(), nums.end());
        auto sum{0};
        for (auto i = 0; i < queries.size(); ++i) {
            sum = 0;
            for (auto j = 0; j <= nums.size(); ++j) {
                if (j == nums.size()) {
                    ans[i] = j;
                }
                else if (sum + nums[j] <= queries[i]) {
                    sum += nums[j];
                } 
                else {
                    ans[i] = j;
                    break;
                }
            }
        }
        return ans;
    }
};