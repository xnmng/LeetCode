// https://leetcode.com/problems/continuous-subarray-sum/discuss/99499/Java-O(n)-time-O(k)-space
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp{{0,-1}};
        auto sum{0};
        auto itr{mp.end()};
        for (auto i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            itr = mp.find(sum % k);
            if (itr != mp.end()) {
                if (i - itr->second > 1) return true;
            } else {
                mp[sum % k] = i;
            }
        }
        return false;
    }
};

// [0]
// 1
// [1,0]
// 2
// [5,0,0,0]
// 3
// [23,6,9]
// 6
// [23,2,4,6,6]
// 7
// [0,1,0,3,0,4,0,4,0]
// 5
// [1,2,3]
// 5
// https://leetcode.com/submissions/detail/830379600/testcase/

// [23,25,29,35,41]
// [2,4,1,0,6]
