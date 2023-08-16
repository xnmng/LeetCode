// https://leetcode.com/problems/sliding-window-maximum/discuss/871317/Clear-thinking-process-with-PICTURE-brute-force-to-mono-deque-pythonjavajavascript
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        ans.reserve(nums.size() - k + 1);
        deque<pair<int,int>> dq; // {index, value}
        for (auto i = 0; i < nums.size(); ++i) {
            while (!dq.empty()) {
                if (i - k >= dq.front().first) {
                    // cout << "remove {" << dq.front().first << " " << dq.front().second << "}\n";
                    dq.pop_front();
                } else if (dq.back().second < nums[i]) {
                    // cout << "remove {" << dq.front().first << " " << dq.front().second << "}\n";
                    dq.pop_back();
                } else break;
            }
            dq.emplace_back(i, nums[i]);
            // cout << "insert {" << i << " " << nums[i] << "}\n";
            // cout << "deque state: \n";
            // for (auto i : dq) {
                // cout << i.first << " " << i.second << "\n";
            // }
            if (i + 1 >= k) {
                // cout << i << " ans add {" << dq.front().first << " " << dq.front().second << "}\n";
                ans.emplace_back(dq.front().second);
            }
        }
        return ans;
    }
};
// [1,3,1,2,0,5]
// 3