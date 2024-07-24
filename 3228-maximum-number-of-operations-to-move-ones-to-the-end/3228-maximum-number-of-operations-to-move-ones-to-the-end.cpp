class Solution {
public:
    // https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/discuss/5508962/Greedy
    //
    // dont need to actually perform the swaps! just count;
    // each time we encounter a sequence of 0's, we need to move our prefix of 1's
    int maxOperations(string s) {
        int ans = 0;
        int count = 0;
        int index = 0;
        int n = s.size();
        while (index < n) {
            if (s[index] == '1') ++count;
            else {
                // s[index] == 0
                ans += count;
                while (index + 1 < n && s[index + 1] == '0') ++index;
            }
            ++index;
        }
        return ans;
    }
};