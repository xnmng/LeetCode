class Solution {
public:
    // let remainder := n % k
    // then, when divided by k, (n * 10 + 1) has the same remainder as (remainder * 10 + 1) 
    // we can simply keep track of remainder rather than the entire n
    // 
    // if the n does not exist, we will see a repeated remainder  
    //
    // if we divide by k, possible remainders are from [0, k-1]
    // by pigeonhole principle, loop at most k times, otherwise repeated remainder exists
    //
    // O(k) time, O(1) space
    int smallestRepunitDivByK(int k) {
        int remainder = 0;
        for (int i = 1; i <= k; ++i) {
            remainder = (remainder * 10 + 1) % k;
            if (remainder == 0) return i;
        }
        return -1;
    }
};