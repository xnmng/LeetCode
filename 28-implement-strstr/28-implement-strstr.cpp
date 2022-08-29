class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        return haystack.find(needle) != string::npos ?
            haystack.find(needle) :
            -1;
    }
};