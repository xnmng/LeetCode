class Solution {
public:
    // recall:
    //      odd + odd = even
    //      even + even = even
    //      odd + even = odd
    //      even + odd = odd
    //
    // this forms 3 sequences:
    //      odd, odd, odd, odd, ...
    //      odd, even, odd, even ...
    //      even, even, even, even ...
    //
    // iterate across nums, check all 3 sequences and return longest one
    int maximumLength(vector<int>& nums) {
        int allOdd;
        int allEven;
        int alternating = 1;
        bool isOdd; // flag indicating what next number in sequence should be
        
        // init base case
        if (nums[0] % 2 == 0) {
            allOdd = 0;
            allEven = 1;
            isOdd = true;
        } else {
            allOdd = 1;
            allEven = 0;
            isOdd = false; 
        }
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] % 2 == 0) {
                ++allEven;
                if (!isOdd) {
                    ++alternating;
                    isOdd ^= true;
                }
            }
            else {
                ++allOdd;
                if (isOdd) {
                    ++alternating;
                    isOdd ^= true;
                }
            }
        }
        
        return max(allOdd, max(allEven, alternating));
    }
};