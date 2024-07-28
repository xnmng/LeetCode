class Solution {
public:
    // special numbers are very sparse
    int nonSpecialCount(int l, int r) {
        int i = static_cast<int>(sqrt(r));
        auto v = sieve(i);
        int ans = r - l + 1;
        for (auto j : v) {
            if (j * j >= l) {
                --ans;
            }
        }
        return ans;
    }
    
    std::vector<int> sieve(int limit) {
        std::vector<bool> is_prime(limit + 1, true);
        is_prime[0] = is_prime[1] = false; // 0 and 1 are not prime numbers

        for (int i = 2; i * i <= limit; ++i) {
            if (is_prime[i]) {
                for (int j = i * i; j <= limit; j += i) {
                    is_prime[j] = false;
                }
            }
        }

        std::vector<int> primes;
        for (int i = 2; i <= limit; ++i) {
            if (is_prime[i]) {
                primes.push_back(i);
            }
        }

        return primes;
    }
};
