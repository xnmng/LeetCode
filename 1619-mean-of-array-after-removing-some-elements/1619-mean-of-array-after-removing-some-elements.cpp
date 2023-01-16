class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        auto sum{0};
        for (auto i = static_cast<int>(0.05 * arr.size()); i < static_cast<int>(arr.size() * 0.95); ++i) {
            sum += arr[i];
        }
        return sum / (0.9 * arr.size());
    }
};