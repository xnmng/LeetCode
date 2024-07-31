class Solution {
public:
    // sort, calculate the total sum, then iterate
    // assume at index i, beans[i] is the optimal amount
    // calculate the number of beans removed based on that
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        int n = beans.size();
        long long total = 0;
        for (auto i : beans) {
            total += i;
        }
        long long sum = 0;
        long long ans = LLONG_MAX;
        for (int i = 0; i < n; ++i) {
            // actual formula; evaluate to bottom statement
            // ans = min(ans, sum + total - sum - (long long) (n-1-i+1) * beans[i]);
            ans = min(ans, total - (long long) (n-i) * beans[i]);
            sum += i;
        }
        return ans;
    }
    
    // sort, then go in reverse order, calculate number of beans removed
    // long long minimumRemoval(vector<int>& beans) {
    //     sort(beans.begin(), beans.end());
    //     int n = beans.size();
    //     vector<long long> prefixSum(n, 0);
    //     prefixSum[0] = beans[0];
    //     for (int i = 1; i < n; ++i) {
    //         prefixSum[i] = prefixSum[i-1] + beans[i];
    //     }
    //     int sum = 0;
    //     // edge case our for-loop doesnt account for; 
    //     //      if the beginning of arr value is the optimal number
    //     long long ans = prefixSum[n-1] - (long long) n * beans[0];
    //     for (int i = n-1; i >= 1; --i) {
    //         long long extra = prefixSum[n-1] - prefixSum[i] 
    //                             - (long long) (n-1 - i) * beans[i];
    //         // cout << extra << " " << prefixSum[i-1] << "\n";
    //         ans = min(ans, prefixSum[i-1] + extra);
    //     }
    //     return ans;
    // }
};