class Solution {
public:
    // general idea:
    // https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-ii/discuss/5690439/From-brute-force-to-cycle-detection-or-Python
    //
    // not just min element,
    // we need to make sure each number is 
    // guaranteed to be greater than max(nums) after operation
    // the way to ensure this is by making sure we apply each multiplication 
    // TO EACH NUM AT LEAST ONCE!
    // https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-ii/discuss/5687003/Min-Heap-oror-Greedy
    // https://youtu.be/roMuKpB5KSY?si=x4OFftA_ula2IShx
    // 
    // naively applying the operations will TLE. how to optimize?
    // when min(nums[i]) * multiplier > max(nums[i]), we get a cycle!
    // eg suppose nums (in sorted order) is 
    //      n1 n2 ... nMax where n1 < n2 < ... < nMax
    // after operation on n1, we get 
    //      n2 ... nMax (n1*k) where n1 < n2 < ... < nMax < (n1*k)
    // we can get the number of cycles (k / n.size()) and apply them all at once, (O(n) time)
    //
    // implementation details:
    // we might get a very large multiplier (10^6) that we need to apply many times to each number
    // (min cycles we can have using max constraints is ~10^5)
    // how to compute this multiplication and take modulo of (1e9+7) ?
    // 
    // 
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if (multiplier == 1) return nums;
        
        // apply the operations until we get the cycle condition
        // i.e. min(nums[i]) * mult. > max(nums[i])
        
        // <num, index_of_num>
        auto comp = [](pair<long,int> a, pair<long,int> b) {
            if (a.first == b.first) return a.second > b.second;  
            return a.first > b.first;
        };
        priority_queue<pair<long,int>, vector<pair<long,int>>, decltype(comp)> pq;
        int largest = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            pq.emplace(nums[i], i);
            largest = max(largest, nums[i]);
        }
        while (k > 0) {
            auto [num, index] = pq.top();
            // cout << num << " " << index << "\n";
            // num = multiply(num, multiplier);
            // do not use multiply function here since it automatically does mod for us!
            if (num * multiplier > largest) {
                break;                
            } else {
                pq.pop();
                // when we add back then we can use multiply function
                pq.emplace(multiply(num, multiplier), index);
                // nums[index] = num;
                --k;
            }            
        }
        // for (auto i : nums) cout << i << " ";
        // cout << "\n";
        
        // perform the cycle multiplication and return
        int cycles = k / n;
        int extra = k % n;
        while (!pq.empty()) {
            auto [num, index] = pq.top();
            pq.pop();
            // cout << num << " " << index << "\n";
            num = cycleMultiply(num, cycles + (extra > 0), multiplier);
            // cout << num << "\n";
            --extra; // doesnt matter if extra is a negative val
            nums[index] = num;
        }
        
        return nums;
    }
    
    // returns (num * (mult^ops)) % 1e9+7
    int cycleMultiply(long num, long ops, long mult) {
        long modulo = 1e9+7;
        // num %= modulo;
        long res = (power(mult, ops)) % modulo;
        // cout << res << "\n";
        return (int) multiply(num, res);
    }
    
    // calculates (a ^ b) % 1e9 + 7
    long power(long a, long b) {
        if (b == 0) return 1;
        if (b % 2 == 1) return multiply(a, power(a, b - 1));
        return power(multiply(a, a), b / 2);
    }
    
    // returns (x * y) % 1e9 + 7 
    long multiply(long x, long y) {
        long modulo = 1e9+7;
        x %= modulo;
        y %= modulo;
        return ((x * y) % modulo);
    }
};
// [66307295,441787703,589039035,322281864]
// 900900704
// 641725