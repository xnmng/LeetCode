// https://leetcode.com/problems/minimum-penalty-for-a-shop/solution/
class Solution {
public:
    // 2 pass intuition:
    // At any index, the penalty is the sum of prefix count of ‘N’ and suffix count of ‘Y’.
    //
    // 1 pass intuition:
    // we only require the index, need not calculate the exact penalty score
    // set index 0 as a penalty of 0 (relative point)
    int bestClosingTime(string customers) {
        int ans{0};
        int minCount{0};
        int curCount{0};
        for (auto i = 0; i < customers.size(); ++i) {
            if (customers[i] == 'Y') {
                --curCount;
            } else {
                ++curCount;
            }
            
            if (curCount < minCount) {
                ans = i+1;
                minCount = curCount;
            }
        }
        return ans;
    }
};