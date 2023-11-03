class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int index = 0;
        vector<string> ans;
        for (auto i = 1; i <= n; ++i) {
            if (index == target.size()) break;
            ans.emplace_back("Push");
            if (target[index] != i) {
                ans.emplace_back("Pop");                    
            } else {
                ++index;
            }
        }
        return ans;
    }
};