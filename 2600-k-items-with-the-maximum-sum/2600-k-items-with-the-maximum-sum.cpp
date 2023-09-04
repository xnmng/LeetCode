class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int ans = min(numOnes, k);
        k -= min(numOnes, k);
        if (k == 0) return ans;
        k -= min(numZeros, k);
        if (k == 0) return ans;
        ans -= min(numNegOnes, k);
        return ans;
    }
};