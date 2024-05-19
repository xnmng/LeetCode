// tbh, dont really understand the DP solution; problem is greedy in nature
// greedy solution, not the best O(nlogn) time, O(n) space
// https://youtu.be/bnBp6_b4GCw?si=lCxcqyraYWqg60eh

class Solution {
public:
    // we dont actually need to use edges lol
    // why?
    // since a tree is undirected, acyclic and connected, we can always XOR any two nodes with k
    // e.g. in a path from node a to b, 
    //      all nodes between (and excluding) a and b will be XOR-ed twice, 
    //      leaving them unchanged
    // 
    // we also know that a XOR k XOR k = a (i.e. applying XOR twice gives us back our intial val)
    // XOR is also commutative (i.e. a XOR b == b XOR a)
    //
    // what should be our strategy?
    // - sum up all values in the tree
    // - calculate delta (i.e. node val XOR k)
    // - keep track of number of positive delta(s)
    // - if delta is positive, add to ans as well
    // - keep track if the smallest positive delta, and the largest negative delta
    // - if we have an even number of positive values, return
    // - if we have an odd number of positive values, return whichever is larger
    //   (i.e. excluding/including (smallestPositive + largestNegative))
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long ans = 0;
        int smallestPositive = INT_MAX;
        int smallestNegative = INT_MIN;
        int count = 0;
        int delta;
        
        for (auto i : nums) {
            ans += i;
            delta = (i ^ k) - i;
            if (delta > 0) {
                ans += delta;
                smallestPositive = min(smallestPositive, delta);
                ++count;
            } else {
                smallestNegative = max(smallestNegative, delta);
            }
        }
        
        if (count % 2 == 0) return ans;
        // note we already added smallestPositive to ans during iteration
        return max(ans - smallestPositive, ans + smallestNegative);
    }
};
// [24,78,1,97,44]
// 6
// [[0,2],[1,2],[4,2],[3,4]]