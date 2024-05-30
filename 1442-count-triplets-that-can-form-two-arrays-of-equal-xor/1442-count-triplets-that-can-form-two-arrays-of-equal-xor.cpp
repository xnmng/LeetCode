class Solution {
public:
    // https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/discuss/623747/JavaC++Python-One-Pass-O(N4)-to-O(N)
    //
    //
    // https://youtu.be/e4Yx9KjqzQ8?si=9DCiiDJ4OjGSF6qu
    //
    // use the property that:
    // - a XOR a = 0
    //
    // O(n) time O(n) space; prefix sum
    int countTriplets(vector<int>& arr) {
        int ans = 0;
        int cur = 0;
        int n = arr.size();
        unordered_map<int,int> count{{0,1}};
        unordered_map<int,int> total;
        for (int i = 0; i < n; ++i) {
            cur ^= arr[i];
            ans += i * count[cur] - total[cur];
            ++count[cur];
            total[cur] += i + 1; 
            
        }
        return ans;
    }
    //
    // O(n^2) time O(1) space
    // int countTriplets(vector<int>& arr) {
    //     int ans = 0;
    //     int n = arr.size();
    //     int cur;
    //     for (int i = 0; i < n-1; ++i) {
    //         cur = arr[i];
    //         for (int j = i+1; j < n; ++j) {
    //             cur ^= arr[j];
    //             if (cur == 0) {
    //                 ans += j - i;
    //             }
    //         }
    //     }
    //     return ans;
    // }
};