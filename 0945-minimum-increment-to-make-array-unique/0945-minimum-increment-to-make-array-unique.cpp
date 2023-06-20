// O(n) union find solution ???
// https://leetcode.com/problems/minimum-increment-to-make-array-unique/discuss/197687/JavaC++Python-Straight-Forward


// https://leetcode.com/problems/minimum-increment-to-make-array-unique/solution/

// O(m+n) time, O(m+n) space
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        auto maximum{INT_MIN};
        auto minimum{INT_MAX};
        for (auto i : nums) {
            maximum = max(i, maximum);
            minimum = min(i, minimum);
        }
        
        vector<int> v(maximum - minimum + nums.size() + 1, 0);
        auto ans{0};
        for (auto i : nums) {
            ++v[i - minimum];
        }
        for (auto i = 0; i < v.size(); ++i) {
            if (v[i] > 1) {
                ans += v[i] - 1;
                v[i+1] += v[i] - 1;
            }
        }
        return ans;
    }
};
// [0]
// [1,2,2]

// O(nlogn) time, O(n) space (based on sorting)
// class Solution {
// public:
//     int minIncrementForUnique(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         auto ans{0};
//         auto prev{nums[0]};
//         for (auto i = 1; i < nums.size(); ++i) {
//             if (nums[i] <= prev) {
//                 ans += (prev + 1) - nums[i];
//                 ++prev;
//             } else {
//                 prev = nums[i];                
//             }
//         }
//         return ans;
//     }
// };