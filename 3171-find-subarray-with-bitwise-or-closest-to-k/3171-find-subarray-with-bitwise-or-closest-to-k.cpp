class Solution {
public:
    // idea inspired by subarray sum equals k (note: 2 pointer works because of monotonic property)
    // we just need some way to perform 2 pointers using OR operator (cant use summing like in subarray sum equals k)
    //
    // use vector to encode the bits of the number, adding will be to add to the respective bits in v[i]
    // (ith index is ith bit; i.e. 2^i)
    // we can get the number, add and remove number to our encoding in O(32) -> O(1) time
    // perform 2 pointers with this
    
    // O(n) time, O(1) time
    int minimumDifference(vector<int>& nums, int k) {
        int ans = INT_MAX;
        vector<int> v(30); // 2^30 > 10^9; 30 bits is enough
        int left  = 0;
        int right = 0;
        int n = nums.size();
        int cur;
        while (right < n) {
            add(v, nums[right]);
            cur = getNum(v);
            ans = min(ans, abs(cur - k));
            ++right;
            while (cur >= k) {
                remove(v, nums[left]);
                cur = getNum(v);
                if (cur > 0) ans = min(ans, abs(cur - k));
                ++left;
            }
        }
        return ans;
    }

    // returns actual number from bitset representation v
    int getNum(vector<int>& v) {
        int ans = 0;
        for (int i = 0; i < 30; ++i) {
            if (v[i] > 0) ans += pow(2, i);
        }
        return ans;
    }
    
    // remove num from bitset representation v
    void add(vector<int>& v, int num) {
        for (int i = 0; i < 30; ++i) {
            if ((num & (int)pow(2, i)) > 0) {
                ++v[i];
            }
        }
    }
    
    // remove num from bitset representation v
    void remove(vector<int>& v, int num) {
        for (int i = 0; i < 30; ++i) {
            if ((num & (int)pow(2, i)) > 0) {
                --v[i];
            }
        }
    }
};
// [1,10]
// 6
// [6]
// 2