// https://youtu.be/2dhjOHe1zvA
// https://leetcode.com/problems/set-mismatch/discuss/1090616/C++-Fastest-Linear-Solution:-3-Versions-Compared-and-Explained-100-Time-~90-Space



// use math formula, use hashset, use input arr set flag, (TODO) use XOR
class Solution {
public:
    // use math, form 2 simultaneous equations and solve
    // O(n) time, O(1) space
        /*
        expectedProd / actualProd =  missing / duplicate    --- (1)
        expectedSum - actualSum = missing - duplicate       --- (2)
        
        missing = duplicate * (expectedProd / actualProd) --- from (1), (3)
        duplicate = missing - (expectedSum - actualSum)   --- from (2), (4)
        
        expectedSum - actualSum = duplicate * (expectedProd / actualProd) - duplicate 
            --- substitute (3) into (2)
        expectedSum - actualSum = duplicate * ((expectedProd / actualProd) - 1) 
            --- factorize
        duplicate = (expectedSum - actualSum) / ((expectedProd / actualProd) - 1) 
            --- make dup the subject, use this to solve
    */
    // vector<int> findErrorNums(vector<int>& nums) {
    //     double division = 1.0; // missing / duplicate; init to 1 to avoid issues
    //     double difference = 0;  // missing - duplicate
    //     int n = nums.size();
    //     for (auto i = 0; i < n; ++i) {
    //         division = division * (i+1) / nums[i];
    //         difference = difference + (i+1) - nums[i];
    //     }
    //     cout << division << " " << difference << "\n";
    //     int duplicate = difference / (division - 1);
    //     int missing = duplicate * division;
    //     return {duplicate, missing};
    // }

    // use input arr, set -1 flag and find both numbers
    // O(n) time, O(1) space (using input)
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2); // [duplicate, missing]
        for (auto i = 0; i < nums.size(); ++i) {
            if (nums[abs(nums[i])-1] < 0) {
                ans[0] = abs(nums[i]);
                continue;
            }
            nums[abs(nums[i])-1] *= -1;
        }
        for (auto i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                ans[1] = i+1;
                break;
            }
        }
        return ans;
    }
};

// [1,3,3]
// https://leetcode.com/submissions/detail/828304551/testcase/