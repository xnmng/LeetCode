// https://leetcode.com/problems/backspace-string-compare/solution/
class Solution {
public:
    // constant space solution: 2 pointers, iterate from behind
    bool backspaceCompare(string s, string t) {
        int left = s.size()-1;
        int leftSkip = 0;
        int right = t.size()-1;
        int rightSkip = 0;
        while (left >= 0 || right >= 0) {
            if ((left >= 0 && s[left] == '#') 
                || (right >= 0 && t[right] == '#')) {
                while (left >= 0 && (leftSkip > 0 || s[left] == '#')) {
                    if (s[left] == '#') {
                        ++leftSkip;
                    } else if (leftSkip > 0) {
                        --leftSkip;
                    }
                    --left;
                }
                while (right >= 0 && (rightSkip > 0 || t[right] == '#')) {
                    if (t[right] == '#') {
                        ++rightSkip;
                    } else if (rightSkip > 0) {
                        --rightSkip;
                    }
                    --right;
                }  
            }
            else {
                // cout << left << " " << right << "\n";
                if (left < 0 || right < 0 || s[left] != t[right]) return false;
                --left;
                --right;
            }            
        }
        // cout << left << " " << right << "\n";
        return left < 0 && right < 0;
    }
};
// "nzp#o#g"
// "b#nzp#o#g"
// "bxj##tw"
// "bxj###tw"
// "rheyggodcclgstf"
// "#rheyggodcclgstf"