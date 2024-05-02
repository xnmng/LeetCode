class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;
        unordered_set<int> s;
        for (auto i : nums) {
            if (abs(i) >= abs(ans)) {
                s.insert(i);
                if (s.find(-1 * i) != s.end()) ans = abs(i);
            }
        }
        return ans;
    }
};