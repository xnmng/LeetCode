class Solution {
public:
    // since we can only perform one op per index, 
    // find the largest prime p such that nums[i] - p < nums[i+1] holds
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        int num;
        for (int i = n-2; i >= 0; --i) {
            if (nums[i] >= nums[i+1]) {
                num = helper(nums[i], nums[i+1]);
                if (num < 0 || (nums[i] - num) >= nums[i+1]) return false;
                nums[i] -= num;                
            }
        }
        return true;
    }
    
    // Sieve of Eratosthenes (modified)
    int helper(int n, int next) {
        if (n <= 1) return -1;
        
        vector<bool> isPrime(n, true);
        isPrime[0] = false;
        isPrime[1] = false;

        for (int i = 2; i * i < n; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        for (int i = 2; i < n; ++i) {
            if (isPrime[i] && (n - i) < next) {
                return i;
            }
        }

        return -1;
    }
};