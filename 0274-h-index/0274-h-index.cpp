class Solution {
public:
    // copied and modified from part II
    // difference: sort first.
    // since its already sorted, we can linear search for i
    // but since they want log, we can improve linear by doing binary search instead
    int hIndex(vector<int>& v) {
        sort(v.begin(), v.end());
        int n = v.size();
        int left = 0;
        int right = n - 1;
        int mid;
        int ans = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (v[mid] >= n - mid) {
                ans = max(ans, n - mid);
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return ans;
    }
};