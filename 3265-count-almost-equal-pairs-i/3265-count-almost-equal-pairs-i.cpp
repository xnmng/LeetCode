class Solution {
public:
    // can just brute force nums
    // https://leetcode.com/problems/count-almost-equal-pairs-i/discuss/5687056/Easy-simulationGreedy-approach
    int countPairs(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (check(nums[i], nums[j])) ++ans;
            }
        }
        return ans;
    }
    
    // check that diff count is 2, 
    // then check that both indexes that have the diff are the same number
    bool check(int a, int b) {
        if (a == b) return true;
        string s1 = to_string(a);
        string s2 = to_string(b);
        // prepend extra leading zeroes
        if (s1.length() < s2.length()) {
            s1 = string(s2.length() - s1.length(), '0') + s1;
        } 
        else if (s2.length() < s1.length()) {
            s2 = string(s1.length() - s2.length(), '0') + s2;
        }
        int n = s1.size();
        int count = 0;
        vector<int> v;
        v.reserve(n);
        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i]) {
                ++count;
                v.emplace_back(i);
            }
        }
        if (count != 2) return false;
        return s1[v[0]] == s2[v[1]] && s2[v[0]] == s1[v[1]];
    }
};
// [5,12,8,5,5,1,20,3,10,10,5,5,5,5,1]