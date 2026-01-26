class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        int diff = INT_MAX;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        for (int i = 1; i < n; ++i) {
            if (arr[i] - arr[i-1] < diff) {
                ans = {{arr[i-1], arr[i]}};
                diff = arr[i] - arr[i-1];
            }
            else if (arr[i] - arr[i-1] == diff) {
                ans.emplace_back(vector<int>{arr[i-1], arr[i]});
            }
        }
        return ans;
    }
};