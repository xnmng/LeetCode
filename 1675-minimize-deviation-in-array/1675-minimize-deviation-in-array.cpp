// https://leetcode.com/problems/minimize-deviation-in-array/discuss/955262/C++-intuitions-and-flip
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        auto maxi{INT_MIN};
        auto mini{INT_MAX};
        priority_queue<int> pq;
        for (auto& i : nums) {
            if (i % 2 == 1) i *= 2;
            mini = min(mini, i);
            pq.push(i);
        }
        int cur;
        int ans{INT_MAX};
        while (pq.top() % 2 == 0) {
            cur = pq.top();
            pq.pop();
            ans = min(cur - mini, ans);
            mini = min(cur / 2, mini);
            pq.push(cur / 2);
        }
        return min(ans, pq.top() - mini);
    }
};
// [3,5]