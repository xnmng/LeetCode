class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count = 0;
        for (auto i : s) {
            if (i == '1') ++count;
        }
        return string(count-1, '1') + string(s.size() - count, '0') + "1";
    }
};