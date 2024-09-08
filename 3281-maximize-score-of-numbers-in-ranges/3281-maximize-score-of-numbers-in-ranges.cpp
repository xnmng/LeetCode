class Solution {
public:
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(), start.end());
        int left = 0;
        int right = INT_MAX;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (helper(start, d, mid)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left - 1;
    }
    
    bool helper(vector<int>& start, int d, int k) {
        int prev = start[0];
        int n = start.size();
        for (int i = 1; i < n; ++i) {
            if (prev + k > start[i] + d) return false;
            prev = max(prev + k, start[i]);
        }
        return true;
    }
};