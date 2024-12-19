class Solution {
public:
    // find each possible k such that arr[0:k] contains 0 to k-1
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int maximum = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            maximum = max(maximum, arr[i]);
            if (maximum == i) ++ans;
        }
        return ans;
    }
};