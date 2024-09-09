// TODO: read other possible solution approaches
// https://leetcode.com/problems/sum-of-floored-pairs/discuss/1210025/Prefix-Sum-Fenwick-Tree-Sort-and-Sieve
class Solution {
public:
    // brute force obviously TLE's, how do we optimize?
    // for a given number k, we want numbers greater than k
    // OK to sort input since n ~ 10^5, nlogn is acceptable
    // binary search for numbers that are >= k
    // (we dont care about < k since floor of that is 0)
    // if we are at a number k, [k, 2k-1] will give 1, [2k, 3k-1] will give 2, ...
    // search for each interval and add to ans accordingly
    // optimization can be to compress nums to only distinct numbers and calculate there
    //
    // (instead of calculating each interval can do it this way)
    // another way to think about the calculation is that at nums[i] = k, 
    // the amount k contributes after multiplying with all other nums in arr (including itself)
    // will be in the pattern [0,...,0,1,..,1,2,...,2,...]
    // at each nums[i], we find the index of numbers that are >= k, 2k, 3k, ...
    // then add n-i and repeat till no more numbers are left
    // 
    // note: we MUST perform compression! else will TLE (think: [1,1,...,10000])
    // how do we calculate all the 1's without TLE?
    // we should calculate for all 1's at once! dont recalculate ans for nums[i] == 1 many times
    // maintain a freq variable and increment while we find same value in nums, then skip those indexes
    //
    // (sort and calculate approach)
    int sumOfFlooredPairs(vector<int>& nums) {
        int modulo = 1e9+7;
        long ans = 0;
        unordered_map<int,int> mp;
        for (int i : nums) ++mp[i];
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int freq = 1;
            while (i+1 < n && nums[i] == nums[i+1]) {
                ++i;
                ++freq;
            }
            // cout << "at " << nums[i] << " " << freq << "\n";
            int cur = 1;
            int prevIndex = -1;
            while (true) {
                auto leftItr = lower_bound(nums.begin(), nums.end(), nums[i] * cur);
                // no more valid partition; we are done calculating
                if (leftItr == nums.end()) break;
                if (distance(nums.begin(), leftItr) == prevIndex) continue;
                // cout << "k = " << cur << " at index " << distance(nums.begin(), leftItr) << "\n";
                long count = distance(leftItr, nums.end());
                // cout << count << "\n";
                ans = (ans + freq * count) % modulo;
                ++cur;
            }
            // cout << "ans=" << ans << "\n";
        }
        return ans;
    }
};