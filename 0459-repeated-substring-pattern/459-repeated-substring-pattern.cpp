class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        auto check{s+s};
        check.pop_back();
        return check.find(s, 1) != string::npos;
    }
};

