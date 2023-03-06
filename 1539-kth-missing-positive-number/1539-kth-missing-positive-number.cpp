// https://leetcode.com/problems/kth-missing-positive-number/discuss/779999/JavaC++Python-O(logN)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        auto left{0};
        auto right{arr.size()};
        int mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            // cout << mid << " " << arr[mid] << "\n";
            if (arr[mid] - mid - 1 < k) left = mid + 1;
            else right = mid;
            // cout << left << " " << right << "\n";
        }
        return left + k;
    }
};

// class Solution {
// public:
//     int findKthPositive(vector<int>& arr, int k) {
//         int next{1};
//         for (auto i : arr) {
//             if (i == next) ++next;
//             else if (k > i - next) {
//                 k -= i - next;
//                 next = i+1;
//             }
//             else break;
//         }
//         return next + k - 1;
//     }
// };