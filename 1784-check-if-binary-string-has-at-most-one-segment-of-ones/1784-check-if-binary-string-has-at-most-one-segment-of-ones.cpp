class Solution {
public:
    bool checkOnesSegment(string s) {
        auto hasOneSegment{false};
        for (auto i = 0; i < s.size(); ++i) {
            if (i > 0 && hasOneSegment && s[i-1] == '0' && s[i] == '1') return false;
            if (s[i] == '1') hasOneSegment = true;
        }
        return true;
    }
};