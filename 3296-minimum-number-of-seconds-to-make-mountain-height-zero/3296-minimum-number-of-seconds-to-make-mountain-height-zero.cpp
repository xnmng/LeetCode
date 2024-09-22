class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long left = 0;
        long long right = LLONG_MAX;
        
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (canReduce(mountainHeight, workerTimes, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
    
private:
    bool canReduce(int mountainHeight, vector<int>& workerTimes, long long time) {
        long long totalReduction = 0;
        for (int i : workerTimes) {
            // derive this formula from solving the inequality
            long long x = (sqrt(1 + 8.0 * time / i) - 1) / 2;
            totalReduction += x;
            if (totalReduction >= mountainHeight) return true;
        }
        return false;
    }
};
// 100000
// [1]