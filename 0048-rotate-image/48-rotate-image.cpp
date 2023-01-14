class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        auto n{arr.size()};
        auto temp{0};
        for (auto i = 0; i < n/2; ++i) {
            for (auto j = i; j < n-i-1; ++j) {
                // notice how the indexes "left shift" across each group of 4
                // cout << arr[i][j] << " " 
                //     << arr[j][n-1-i] << " " 
                //     << arr[n-1-i][n-1-j] << " "
                //     << arr[n-1-j][i] << "\n";
                // cout << "\n";
                temp = arr[n-1-j][i];
                arr[n-1-j][i] = arr[n-1-i][n-1-j];
                arr[n-1-i][n-1-j] = arr[j][n-1-i];
                arr[j][n-1-i] = arr[i][j];
                arr[i][j] = temp;
            }
        }
    }
};