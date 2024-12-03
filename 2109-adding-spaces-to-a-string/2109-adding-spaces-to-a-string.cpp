class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        ans.reserve(s.size() + spaces.size());
        int prev = 0;
        for (int i : spaces) {
            ans += s.substr(prev, i - prev) + " ";
            prev = i;
        }
        ans += s.substr(prev);
        return ans;
    }
};