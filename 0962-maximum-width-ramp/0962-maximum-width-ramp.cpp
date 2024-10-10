class Solution {
public:
    // https://leetcode.com/problems/maximum-width-ramp/discuss/265765/Detailed-Explaination-of-all-the-three-approaches
    //
    // stack approach
    // O(n) time, O(n) space
    int maxWidthRamp(vector<int>& nums) {
        stack<int> s;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (s.empty() || nums[s.top()] > nums[i]) {
                s.push(i);
            }
        }
        int ans = 0;
        for (int i = n-1; i >= 0; --i) {
            // 'while' and not 'if' because this index i could have a better match inside the stack
            // e.g. if stack is [5,2,1,0] and nums[i] = 1, this index can match with 1 and 0
            while (!s.empty() && nums[s.top()] <= nums[i]) {
                cout << i << " " << s.top() << "\n";
                ans = max(ans, i - s.top());
                s.pop();
                if (s.empty()) break;
            }
        }
        return ans;
    }
};