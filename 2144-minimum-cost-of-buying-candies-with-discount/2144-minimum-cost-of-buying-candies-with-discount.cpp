class Solution {
public:
    int minimumCost(vector<int>& arr) {
        sort(arr.rbegin(), arr.rend());
        int ans = 0;
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            if (i > 0 && (i+1) % 3 == 0) continue;
            ans += arr[i];
        }
        return ans;
    }
};