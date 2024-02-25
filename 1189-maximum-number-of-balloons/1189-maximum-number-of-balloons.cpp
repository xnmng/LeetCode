class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // 'balloon' requires: 1 'a', 1 'b', 2 'l', 2 'o', 1 'n'
        vector<int> v(26, 0);
        for (char c : text) ++v[c - 'a'];
        return min(v['a' - 'a'], 
                   min(v['b' - 'a'], 
                       min(v['l' - 'a'] / 2, 
                           min(v['o' - 'a'] / 2, v['n' - 'a']))));
    }
};