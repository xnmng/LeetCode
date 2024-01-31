class Solution {
public:
    // monotonic stack (top is smallest element), store index instead of value for easy computation of ans
    // airwallex qn similar idea solution, 
    // they said if output space isnt part of the answer, 
    // can use DP iterate from back for O(n) time O(1) space
    vector<int> dailyTemperatures(vector<int>& temp) {
        auto n{temp.size()};
        vector<int> ans(n, 0);
        stack<int> s;
        for (auto i = 0; i < n; ++i) {
            while (!s.empty() && temp[s.top()] < temp[i]) {
                ans[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};