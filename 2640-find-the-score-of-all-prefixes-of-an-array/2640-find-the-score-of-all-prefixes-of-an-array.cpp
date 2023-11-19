class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> ans;
        ans.reserve(nums.size());
        int maximum = INT_MIN;
        long long sum = 0;
        for (auto i : nums) {
            maximum = max(i, maximum);
            sum += maximum + i;
            ans.emplace_back(sum);
        }
        return ans;
    }
    /*
    conver =    (arr[0] + max(arr[0]), 
                arr[1] + max(arr[0..1]), 
                arr[2] + max(arr[0..2]),
                ...)
                
    ans =       (sum(conver[0]), 
                sum(conver[0..1]), 
                sum(conver[0..2]),
                ...)
    */
};