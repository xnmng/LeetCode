// https://leetcode.com/problems/move-zeroes/discuss/172432/THE-EASIEST-but-UNUSUAL-snowball-JAVA-solution-BEATS-100-(O(n))-+-clear-explanation
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto size{0};
        for (auto i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) ++size;
            else if (size > 0) {
                swap(nums[i], nums[i-size]);
            }
        }
    }
};

// https://leetcode.com/problems/move-zeroes/discuss/72011/Simple-O(N)-Java-Solution-Using-Insert-Index
// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         auto left{0};
//         while (left < nums.size()) {
//             if (nums[left] != 0) ++left;
//             else break;
//         }
//         // cout << left << "\n";
//         if (left == nums.size()) return;
//         auto right{left + 1};
//         while (right < nums.size()) {
//             if (nums[right] != 0) {
//                 swap(nums[left], nums[right]);
//                 ++left;
//             }
//             ++right;
//         }
//         while (left < nums.size()) {
//             nums[left] = 0;
//             ++left;
//         }
//     }
// };

// [2,1]