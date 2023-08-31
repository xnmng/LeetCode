// O(n) time, O(n) space (greedy - reduce problem to 45. Jump Game II)
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> maxReach(n+1);
        for (auto i = 0; i < n+1; ++i) {
            int left = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);
            maxReach[left] = max(maxReach[left], right);
        }
        int ans = 0;
        int curEnd = 0;
        int nextEnd = 0;
        for (auto i = 0; i < n+1; ++i) {
            if (i > nextEnd) return -1;
            if (i > curEnd) {
                ++ans;
                curEnd = nextEnd;
            }
            if (maxReach[i] > nextEnd) {
                nextEnd = maxReach[i];
            }
        }
        return ans;
    }
};
// 6
// [1,0,0,2,0,3,0]
// 7
// [1,2,1,0,2,1,0,1]
// 8
// [4,0,0,0,0,0,0,0,4]
// 11
// [2,1,2,1,2,4,3,0,1,0,5,2]
// 6
// [1,1, 0, 1, 0, 0, 1]
// 5
// [0, 1, 0, 0, 1, 0]
// 35
// [1,0,4,0,4,1,4,3,1,1,1,2,1,4,0,3,0,3,0,3,0,5,3,0,0,1,2,1,2,4,3,0,1,0,5,2]