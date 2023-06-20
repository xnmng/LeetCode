class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        auto n{arr.size()};
        auto ans{0};
        for (auto i = 0; i < n; ++i) {
            for (auto j = i+1; j < n; ++j) {
                for (auto k = j+1; k < n; ++k) {
                    if (abs(arr[i] - arr[j]) <= a 
                        && abs(arr[j] - arr[k]) <= b 
                        && abs(arr[i] - arr[k]) <= c) ++ans;
                }
            }
        }
        return ans;
    }
};