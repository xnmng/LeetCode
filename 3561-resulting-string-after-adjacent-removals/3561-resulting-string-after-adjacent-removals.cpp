class Solution {
public:
    string resultingString(string s) {
        string ans;
        for (char c : s) {
            if (!ans.empty() && helper(ans.back(), c)) {
                ans.pop_back();
                continue;
            }
            ans += c;
        }
        return ans;
    }

    bool helper(char a, char b) {
        if (a == 'a' && b == 'z' || a == 'z' && b == 'a') return true;
        return abs(b - a) == 1;
    }
};