class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        int n = arr.size();
        for (auto i = 1; i < n; ++i) {
            arr[i] = min(arr[i], arr[i-1] + 1);
        }
        return arr.back();
    }
};