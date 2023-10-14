class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        // int count = 0;
        // for (auto i : s) {
        //     if (i == '1') ++count;
        // }
        // return string(count-1, '1') + string(s.size() - count, '0') + "1";
        
        // more performant; only 1 allocation being made
        string ans(s.size(), '0');
        ans.back() = '1';
        int index = -1;
        for (char c : s) {
            if (c == '1') {
                if (index >= 0) ans[index] = '1';
                ++index;
            }
        }
        return ans;
    }
};