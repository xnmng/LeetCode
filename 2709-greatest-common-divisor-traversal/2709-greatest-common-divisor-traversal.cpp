// https://leetcode.com/problems/greatest-common-divisor-traversal/discuss/3568580/Union-Find
class Solution {
public:
    // TODO: recap of udfs, time complexity + space complexity analysis
    // could probably do ufds and check if there is only 1 union
    //
    // based on the question, we can travel between elements if and only if they share gcd > 1
    // (since we know 1 is not a prime number)
    // and if gcd > 1, we know that two numbers will share a prime factor
    // 
    // we can effectively reduce the condition to:
    //      we can travel between two elements a and b iff they share a prime factor
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        // edge case; a graph with 1 node is SCC
        if (n == 1) return true;
        // determine the largest number in nums, O(n) time; 
        // but we could also have just done sieve on largest input (stated in qn constraints)
        int maxNum = 0;
        for (int i : nums) {
            maxNum = max(i, maxNum);
        }
        
        // we only need to sieve up to and including ceil(sqrt(maxNum))
        // the scenario where the prime is a very large number itself (i.e. not in sieve),
        // is handled in the way we try to find the prime factors (see below)
        // (e.g. [49999, 99998], prime = 49999 
        // or [21, 35], prime = 7, but we only sieve(ceil(sqrt(35))) = 6)
        vector<int> primes = sieve(ceil(sqrt(maxNum)));
        // for (auto i : primes) cout << i << " ";
        // cout << "\n";
        
        // //      (unfortunately) testing with maxNum = 100 000, we have 67 prime factors
        // //      not possible to do a bitset
        // // use a 2D array to check for primes;
        // // for a given nums[i], primeFactors[i] contains its prime factors
        // vector<vector<int>> primeFactors;
        // primeFactors.reserve(n);
        // for (int i : nums) primeFactors.emplace_back(getFactorsOf(i, primes));
        
        // (now that we have completed preprocessing) 
        // use union find to determine if input is 1 big strongly connected component (SCC)
        //
        // instead of going through each possible ordered i and j 
        // (i.e. doing O(n^2) work) then union-ing i and j (which will TLE since input is <= 10^5) 
        // we use a hashmap of <prime_factor -> index_in_nums>, 
        // which allows us to check if a given number's prime factors 
        // matches any previously processed number in O(1) time
        //
        // then, we iteratively attempt to reduce nums[i] until it becomes 1, which will give us all its prime factors
        //
        // edge case: if at the end of checking all primes <= ceil(sqrt(maxNum)), nums[i] != 1,
        // we know that (modified) nums[i] is a very large prime, and we add that in as well
        //
        // this is correct because if k is the common prime that a, b, and c share,
        // union a with b and union b with c would cause a b and c to all be in the same component
        unordered_map<int,int> mp; // <prime_factor, index_in_nums>
        vector<int> v(n, -1); // used for UFDS
        for (int i = 0; i < n; ++i) {
            for (int j : primes) {
                // cout << "checking " << nums[i] << " " << j << "\n";
                if (j > nums[i]) break;
                if (nums[i] % j == 0) {
                    // cout << nums[i] << " " << j << "\n";
                    if (mp.find(j) == mp.end()) mp[j] = i;
                    // cout << nums[i] << " " << j << " ok\n";
                    // dont really need an else-block; can union number with itself
                    unionNums(i, mp[j], v);
                    
                    while (nums[i] % j == 0) nums[i] /= j;
                }
            }
            if (nums[i] != 1) {
                if (mp.find(nums[i]) == mp.end()) mp[nums[i]] = i;
                unionNums(i, mp[nums[i]], v);
            }
        }
        
        // since we are checking if all nums form 1 big union,
        // and we are using smallest index (i.e. 0) as root of a union
        // suffices to check if every index has the same root, which will be 0
        //
        // if any index has root that is -1 (i.e. it is in a union with only itself), 
        // or has a root that is not zero, we have discovered >1 component and can early return false
        for (int i = 1; i < n; ++i) if (v[i] == -1 || parent(v[i], v) != 0) return false;
        
        return true;
    }
    
    // normal sieve will suffice, since n is max 10^5
    // sieve of Eratosthenes; O(nloglogn) time
    vector<int> sieve(int n) {
        vector<bool> v(n+1, true);
        for (int i = 2; i < n+1; ++i) {
            if (v[i]) {
                for (int j = i * i; j < n+1; j += i) {
                    v[j] = false;
                }
            }
        }
        
        // output results
        vector<int> ans;
        for(int i = 2; i < n+1; ++i) {
            if (v[i]) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
    
    // vector<int> getFactorsOf(int n, vector<int>& primes) {
    //     vector<int> ans;
    //     for (int i : primes) {
    //         if (i * i > n) break;
    //         if (n % i == 0) ans.emplace_back(i);
    //     }
    //     return ans;
    // }
    
    // union with compression
    void unionNums(int i, int j, vector<int>& v) {
        // cout << "union: " << i << " " << j << "\n";
        if (v[i] == -1 && v[j] == -1) {
            v[i] = min(i, j);
            v[j] = min(i, j);
        } else if (v[i] == -1) {
            v[i] = v[j];
        } else if (v[j] == -1) {
            v[j] = v[i];
        } else {
            int a = parent(i, v);
            int b = parent(j, v);
            v[max(a, b)] = v[min(a, b)];
        }
        // for (auto i : v) cout << i << " ";
        // cout << "\n";
    }
    
    // return parent of this union and in doing so, compress the path
    int parent(int j, vector<int>& v) {
        if (v[j] == j) return j;
        int p = parent(v[j], v);
        v[j] = p;
        return p;
    }
};
// [11]
// [33,60]
// [7,36,14,42]
// [4,3,12,8]
// [3,9,5]
// [21,21,35,20]
// [49999,99998]