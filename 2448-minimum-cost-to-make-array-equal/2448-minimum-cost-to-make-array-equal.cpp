// https://leetcode.com/problems/minimum-cost-to-make-array-equal/discuss/2734162/JavaC++Python-Binary-Search
class Solution {
private:
    long long findCost(vector<int>& nums, vector<int>& cost, int val) {
        long long ans{0};
        for (auto i = 0; i < nums.size(); ++i) {
            ans += 1ll * abs(nums[i] - val) * cost[i];
        }        
        return ans;
    }
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long ans{0};
        auto left{INT_MAX};
        auto right{INT_MIN};
        for (auto i : nums) {
            left = min(left, i);
            right = max(right, i);
        }
        ++right; // to include right in binary search range we need +1
        --left; // to include left in binary search range we need -1
        int mid;
        long long midLeft; // need to be LL else overflow
        long long midRight; // need to be LL else overflow
        while (left < right) {
            mid = left + (right - left) / 2;
            // can compare mid and mid+1 too, but mid-1 and mid+1 doesnt work
            midLeft = findCost(nums, cost, mid-1);
            midRight = findCost(nums, cost, mid);
            ans = min(midLeft, midRight);
            if (midLeft < midRight) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return ans;
    }
};

// [735103,366367,132236,133334,808160,113001,49051,735598,686615,665317,999793,426087,587000,649989,509946,743518]
// [724182,447415,723725,902336,600863,287644,13836,665183,448859,917248,397790,898215,790754,320604,468575,825614]
// [1,2]
// [1,100]