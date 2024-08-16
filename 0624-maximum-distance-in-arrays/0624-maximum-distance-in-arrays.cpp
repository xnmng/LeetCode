class Solution {
public:
    // at each step, only need check front and back elements (sorted property) 
    int maxDistance(vector<vector<int>>& arr) {
        int ans = 0;
        int minimum = arr[0].front();
        int maximum = arr[0].back();
        int n = arr.size();
        for (int i = 1; i < n; ++i) {
            ans = max(ans, 
                      max(arr[i].back() - minimum, 
                          maximum - arr[i].front()));
            minimum = min(arr[i].front(), minimum);
            maximum = max(arr[i].back(), maximum);
        }
        return ans;
    }
};