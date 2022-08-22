class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        auto ans{0};
        auto limit{k * threshold};
        auto cur{0};
        for (auto i = 0; i < arr.size(); ++i) {
            cur += arr[i];
            if (i >= k) {
                cur -= arr[i-k];
            }
            if (cur >= limit && i >= k-1) {
                // cout << i << " " << cur << "\n";
                ++ans;
            }
        }
        return ans;
    }
};