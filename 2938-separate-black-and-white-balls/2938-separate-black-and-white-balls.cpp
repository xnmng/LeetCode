class Solution {
public:
    long long minimumSteps(string s) {
        // goal: 000...111...
        int left = 0;
        int right = s.size()-1;
        long long ans = 0;
        while (right > left) {
            if (s[left] == '0') ++left;
            else if (s[right] == '1') --right;
            else {
                // dont actually need to perform the swap, just count
                // swap(s[left], s[right]);
                ans += right - left;
                ++left;
                --right;
            }
        }
        return ans;
    }
};
// 010001110
