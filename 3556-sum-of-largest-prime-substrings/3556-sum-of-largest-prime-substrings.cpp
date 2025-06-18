class Solution {
public:
    // brute force each substring, check if its prime keep track of top 3
    long long sumOfLargestPrimes(string str) {
        set<long long> s;
        int n = str.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 1; i+j <= n; ++j) {
                // cout << str.substr(i, j) << "\n";
                if (is_prime(stoll(str.substr(i, j)))) {
                    s.insert(stoll(str.substr(i, j)));
                }
            }
        }
        long long ans = 0;
        auto itr = s.rbegin();
        for (int i = 0; i < min(3, (int)s.size()); ++i) {
            // cout << *itr << "\n";
            ans += *itr;
            ++itr;
        }
        return ans;
    }

    bool is_prime(long long num) {
        for (long long i = 2; i * i <= num; ++i) {
            if (num % i == 0) return false;
        }
        return num > 1;
    }
};