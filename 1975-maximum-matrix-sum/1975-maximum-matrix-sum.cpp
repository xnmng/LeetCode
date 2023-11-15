class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0;
        int temp = INT_MAX; // store smallest abs number
        bool flag = false; // whether there exist odd negative numbers or not
        for (auto& i : matrix) {
            for (auto j : i) {
                ans += abs(j);
                if (j < 0) {
                    flag ^= true; // flip boolean
                }
                temp = min(temp, abs(j));
            }
        }
        if (flag) ans -= 2 * temp; // added temp once, remove and subtract temp from sum
        return ans;
    }
};
// [[-1,0,-1],[-2,1,3],[3,2,2]]
// [[2,9,3],[5,4,-4],[1,7,1]]