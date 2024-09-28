class Solution {
public:
    long long maximumTotalSum(vector<int>& arr) {
        sort(arr.begin(), arr.end(), greater<int>());
        long long ans = 0;
        for (int i = 0; i < arr.size(); ++i) {
            if (i > 0) {
                arr[i] = min(arr[i], arr[i-1] - 1);
                if (arr[i] == arr[i-1] || arr[i] <= 0) return -1;
            }
            ans += arr[i];
        }
        // for (int i : arr) cout << i << " ";
        // cout << "\n";
        return ans;
    }
};