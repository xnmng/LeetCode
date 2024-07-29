class Solution {
public:
    // O(n^2) time O(1) space
    // idea: fix middle element, find left and right elements
    //          (for both increasing and decreasing sequence)
    // _ _ _
    //   ^
    // fixed
    int numTeams(vector<int>& rating) {
        int ans = 0;
        int n = rating.size();
        for (int i = 1; i < n-1; ++i) {
            int leftUp = 0;
            int rightUp = 0;
            int leftDown = 0;
            int rightDown = 0;
            // all numbers are distinct
            for (int j = 0; j < i; ++j) {
                if (rating[j] < rating[i]) ++leftUp;
                else ++leftDown;
            }
            for (int j = i+1; j < n; ++j) {
                if (rating[i] < rating[j]) ++rightUp;
                else ++rightDown;
            }
            ans += leftUp * rightUp + leftDown * rightDown;
        }
        return ans;
    }
};