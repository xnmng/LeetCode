class Solution {
public:
    // binary search for solution
    int minDays(vector<int>& arr, int m, int k) {
        if ((long) m * k > arr.size()) return -1;
        int low = 0;
        int high = INT_MAX;
        int mid;
        while (low < high) {
            mid = low + (high - low) / 2;
            if (check(arr, m, k, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
    
    bool check(vector<int>& arr, int m, int k, int cur) {
        int count = 0;
        for (int i : arr) {
            if (cur >= i) {
                ++count;
                if (count == k) {
                    count = 0;
                    --m;
                }
            } 
            else count = 0;
        }
        return m <= 0;
    }
};