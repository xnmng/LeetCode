// https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/discuss/944626/C++-Greedy-Solution-Simple-and-Clear-Explanation
// https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/discuss/944542/C++-Sort-by-Minimum-Actual
class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        // sort by descending order of "energy wastage" (why?)
        sort(tasks.begin(), tasks.end(), 
            [](vector<int>& a, vector<int>& b) {
            return a[1] - a[0] > b[1] - b[0];
        });
        // for (auto i : tasks) {
        //     cout << i[0] << " " << i[1] << "\n";
        // }
        int ans = 0;
        int cur = 0;
        for (auto& i : tasks) {
            if (cur < i[1]) {
                ans += i[1] - cur;
                cur = i[1] - i[0];
            } else {
                cur -= i[0];
            }
        }
        return ans;
    }
};