class Solution {
public:
    // https://youtu.be/wRubz1zhVqk?si=EcNGwPSI48IHizyL
    //
    // we can think of a denary (n = 10) tree of all the numbers, 
    // then perform a preorder traversal to obtain the sorted order.
    //
    // naively, doing a tree traversal or generating all the numbers then sorting them will TLE.
    // how to optimize?
    // 
    // instead of traversing each number in the tree, we can instead count the number of integers in each subtree
    // if the count of this subtree is > k, we know the answer is somewhere inside the subtree
    // else, we skip this subtree and check the one on the right of it 
    // (no need to worry about out of bounds since k <= n)
    //
    // we can calculate the size of the subtree in log10(n) time (helper function)
    // we iterate at most log10(n) times, each step either multiplying the number by 10, or adding 1 to the number
    // (the number of digits a number n has in decimal is log10(n) digits)
    //
    // O(log10(n)^2) time, O(1) space
    int findKthNumber(int n, int k) {
        int cur = 1;
        int rank = 1; // rank-th smallest number in the lexicograhpically sorted range [1, n]
        while (rank < k) {
            int size = count(cur, n);
            if (size + rank <= k) {
                // skip the entire subtree, go to the next (right) one
                // this adjacent subtree has rank size greater than cur
                ++cur;
                rank += size;
            }
            else {
                // if we enter the leftmost subtree rooted at cur,
                // the leftmost subtree root has rank 1 greater than cur
                cur *= 10;
                ++rank;
            }
        }
        return cur;
    }
    
    // counts the number of integers rooted at cur (including cur), bounded by limit
    //
    // SC is due to recursive depth, log10(n) because we have 10 digits in the decimal number system
    //
    // O(log10(n)) time, O(1) space
    int count(long cur, long limit) {
        int ans = 0;
        long adj = cur + 1;
        while (cur <= limit) {
            // if we use limit, as our upper bound, we would be off by 1, hence we add 1
            //      (e.g. from 2000 to min(2513, 3000), limit = 2513, 
            //          there are 514 numbers in the range [2000, 2513], so limit - 2000 + 1)
            ans += min(limit + 1, adj) - cur;
            cur *= 10;
            adj *= 10;
        }
        return ans;
    }
};
// 681692778
// 351251360