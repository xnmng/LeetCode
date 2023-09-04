// https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
// not familar with second optimization
class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) return 0;
        vector<bool> v(n, true);
        int ans{0};
        // either iterate from [2,floor(sqrt(n))] 
        //    and iterate across v from 2 to n and count true
        // or iterate from [2, n] and increment inside loop
        for (long i = 2; i < n; ++i) {
            if (v[i]) {
                ++ans;
                for (long j = i * i; j < n; j += i) {
                    v[j] = false;
                }
            }
        }
        return ans;
    }
};
// 499979