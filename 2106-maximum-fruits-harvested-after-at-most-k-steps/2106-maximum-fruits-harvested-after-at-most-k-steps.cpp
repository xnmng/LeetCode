class Solution {
public:
    // sliding window on the fruits
    // write a step function to calculate number of steps needed to visit [left, right]
    // O(n) time, O(1) space
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int left = 0;
        int right = 0;
        int n = fruits.size();
        int sum = 0;
        int ans = 0;

        while (right < n) {
            sum += fruits[right][1];
            while (left <= right && steps(left, right, fruits, startPos) > k) {
                sum -= fruits[left][1];
                ++left;
            }
            ans = max(ans, sum);
            ++right;
        }

        return ans;
    }

    // calculates the steps needed to visit [left, right] starting from start
    int steps(int left, int right, vector<vector<int>>& fruits, int start) {
        // start is outside of [left, right]
        if (fruits[right][0] <= start) {
            return start - fruits[left][0];
        }
        if (start <= fruits[left][0]) {
            return fruits[right][0] - start;
        }
        // start is inside of [left, right]
        // go left then right
        int a = start - fruits[left][0] + fruits[right][0] - fruits[left][0];
        // go right then left
        int b = fruits[right][0] - start + fruits[right][0] - fruits[left][0];
        return min(a, b);
    }
};