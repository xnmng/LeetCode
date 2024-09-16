class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        set<int> s;
        for (auto& str : timePoints) {
            if (!s.insert(helper(str)).second) return 0;
        }
        int ans = INT_MAX;
        int prev = *s.rbegin();
        for (int i : s) {
            ans = min(ans, helper2(i, prev));
            prev = i;
        }
        return ans;
    }
    
    // parse string to int time (00:00 -> 0, 2359 -> 1439)
    int helper(string& s) {
        int hour = stoi(s.substr(0, 2));
        int minute = stoi(s.substr(3, 2));
        return hour * 60 + minute;
    }
    
    // find the min time difference between two int times
    int helper2(int n1, int n2) {
        if (n1 > n2) return helper2(n2, n1);
        return min(n2 - n1, 24 * 60 - n2 + n1);
    }
};