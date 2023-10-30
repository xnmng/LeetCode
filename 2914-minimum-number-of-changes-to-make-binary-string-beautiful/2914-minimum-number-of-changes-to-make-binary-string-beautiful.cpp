class Solution {
public:
    int minChanges(string s) {
        /*
            For any valid partition, since each part consists of an even number of the same characters, 
            we can further partition each part into lengths of exactly 2.

            After noticing the first hint, we can decompose the whole string into disjoint blocks of size 2 
            and find the minimum number of changes required to make those blocks beautiful.
        */
        int ans = 0;
        for (auto i = 1; i < s.size(); i += 2) {
            if (s[i] != s[i-1]) {
                ++ans;
            }
        }
        return ans;
    }
};
// "11000111"