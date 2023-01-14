class Solution {
    // returns true if the first argument is less than 
    // (i.e. is ordered before) the second.
    bool static c(const string& s1, const string& s2) {
        return s1+s2 > s2+s1;
    }
public:
    string largestNumber(vector<int>& nums) {
        string ans{""};
        vector<string> v;
        for (auto i : nums) {
            v.push_back(to_string(i));
        }
        sort(v.begin(), v.end(), Solution::c);
        for (auto i = 0; i < v.size(); ++i) {
            ans += v[i];
        }
        
        // remove leading zeroes before returning
        for (auto i = 0; i < ans.size(); ++i) {
            if (ans[i] == '0') continue;
            return ans.substr(i);
        }
        return ans.substr(ans.size()-1);
    }
};

// [0,0]
// [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]