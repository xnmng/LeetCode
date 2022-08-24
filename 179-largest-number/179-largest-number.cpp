class Solution {
    // returns true if the first argument is less than 
    // (i.e. is ordered before) the second.
    bool static c(const int& i1, const int& i2) {
        auto s1{to_string(i1) + to_string(i2)};
        auto s2{to_string(i2) + to_string(i1)};
        return s1 > s2;
    }
public:
    string largestNumber(vector<int>& nums) {
        string ans{""};
        sort(nums.begin(), nums.end(), Solution::c);
        for (auto i = 0; i < nums.size(); ++i) {
            ans += to_string(nums[i]);
        }
        for (auto i = 0; i < ans.size(); ++i) {
            if (ans[i] == '0') continue;
            return ans.substr(i);
        }
        return ans.substr(ans.size()-1);
    }
};

// [0,0]
// [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]