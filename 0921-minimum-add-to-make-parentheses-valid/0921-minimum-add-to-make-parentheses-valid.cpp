class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0; // number of opening brackets we need
        int close = 0; // number of closing brackets we need
        for (auto i : s) {
            if (i == '(') ++close;
            // here onwards, we know i == ')'
            else if (close > 0) --close;
            else ++open;
        }
        return open + close;
    }
};
// "()"