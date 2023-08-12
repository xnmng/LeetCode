class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n{static_cast<int>(nums.size())};
        vector<int> ans(n, -1);
        vector<int> v;
        for (int i = 0; i < n; ++i) {
            while (!v.empty() && nums[v.back()] < nums[i]) {
                // cout << "remove " << v.back() << "\n";
                ans[v.back()] = nums[i];
                v.pop_back();
            }
            v.push_back(i);
            // cout << "add " << i << "\n";
        }
        // for (int i : ans) cout << i << " ";
        // cout << "\n";
        // for (int i : v) cout << i << " ";
        // cout << "\n";
        for (int i = 0; i < n; ++i) {
            // cout << v.back() << " " << nums[i] << " " << "\n";
            while (nums[v.back()] < nums[i] && v.size() > 1) {
                // cout << "set index: " << v.back() << " to " << nums[i] << "\n";
                ans[v.back()] = nums[i];
                v.pop_back();
            }
        }
        // for (int i : ans) cout << i << " ";
        // cout << "\n";
        return ans;
    }
};