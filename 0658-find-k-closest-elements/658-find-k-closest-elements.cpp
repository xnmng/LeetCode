class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if (arr.size() <= k) return arr;
        auto left{0};
        auto right{arr.size()-1};
        while (right - left + 1 > k) {
            auto cond{abs(arr[right] - x) == abs(arr[left] - x)};
            if (cond) {
                right > left ? --right : ++left;
            }
            else if (abs(arr[right] - x) > abs(arr[left] - x)) {
                --right;
            } else {
                ++left;
            }
        }
        // cout << left << " " << right << "\n";
        return vector<int>(arr.begin() + left, arr.begin() + right + 1);
    }
};

// [1]
// 1
// 1
// [0,0,1,2,3,3,4,7,7,8]
// 3
// 5
// [0,0,0,1,3,5,6,7,8,8]
// 2
// 2
