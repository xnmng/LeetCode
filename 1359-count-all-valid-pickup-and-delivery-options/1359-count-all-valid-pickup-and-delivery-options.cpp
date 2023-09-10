// https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/discuss/1824163/Java-Simple-O(N)-Explanation-with-Diagrams
// https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/discuss/516933/C++Python-1-line-Simple-permutation-with-explanation
class Solution {
public:
    int countOrders(int n) {
        long modulo = 1e9+7;
        long ans = 1;
        /*
        n! for permuting pickup of n pickups
        (1 * 3 * ... * 2n-1) for number of ways to insert n deliveries 
            for a given permutation of pickups
        */
        for (long i = 1; i <= n; ++i) {
            ans = (ans * i) % modulo;
            ans = (ans * (2 * i - 1)) % modulo;
        }
        return ans;
    }
};