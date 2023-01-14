class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        auto sum{0};
        for (auto i : nums) {
            if (i % 2 == 0) sum += i;
        }
        for (auto i : queries) {
            // if index is even, remove from sum
            // then perform query and check if index is even
            if (nums[i[1]] % 2 == 0) {
                sum -= nums[i[1]];
            }
            nums[i[1]] += i[0];
            if (nums[i[1]] % 2 == 0) {
                sum += nums[i[1]];
            }
            ans.push_back(sum); 
        }
        return ans;
    }
};


// https://leetcode.com/problems/sum-of-even-numbers-after-queries/discuss/231098/C++-O(n)-track-even-sum
// class Solution {
// public:
//     vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
//         vector<int> ans;
//         auto sum{0};
//         for (auto i : nums) {
//             if (i % 2 == 0) sum += i;
//         }
//         for (auto i : queries) {
//             // even + even = even
//             // even + odd = odd
//             // odd + even = odd
//             // odd + odd = even
            
//             if (nums[i[1]] % 2 == 0) { // even
//                 if (i[0] % 2 == 0) {
//                     sum += i[0];
//                 } else {
//                     sum -= nums[i[1]];
//                 }
//                 nums[i[1]] += i[0];
//             } 
//             else { // odd
//                 nums[i[1]] += i[0];
//                 if (nums[i[1]] % 2 == 0) { // add odd to odd, now check if index its even
//                     sum += nums[i[1]];
//                 }
//             }
//             ans.push_back(sum); 
//         }
        
//         return ans;
//     }
// };

// after adding odd to odd, check if index is even!
// [-1,3,-3,9,-6,8,-5]
// [[-5,1],[10,2],[-6,3],[3,2],[9,5],[7,5],[8,0]]