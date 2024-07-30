class Solution {
public:
    // note: i need not be smaller than j!
    //
    // i j -> f(i) f(j)
    // 0 0 ->    0    0 (no point doing this)
    // 1 0 ->    1    1 (can change 0 to 1, needs 1)
    // 0 1 ->    1    1 (can change 0 to 1, needs 1)
    // 1 1 ->    1    0 (can change 1 to 0, needs 1)
    //
    // we only can perform the operation when s/target is NOT all zeroes
    // why? we need a '1' to change the string
    bool makeStringsEqual(string s, string target) {
        int count = 0; // count number of strings that have '1'
        for (auto c : s) {
            if (c == '1') {
                ++count;
                break;
            }
        }
        for (auto c : target) {
            if (c == '1') {
                ++count;
                break;
            }
        }
        // edge case is when both strings are all zeroes
        return count == 2 || count == 0;
    }
};
// "000000"
// "000000"