// https://leetcode.com/problems/shifting-letters-ii/discuss/2454167/Line-Sweep-with-explanation.
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> v(s.size()+1, 0);
        for (auto& i : shifts) {
            if (i[2] == 0) {
                --v[i[0]];
                ++v[i[1]+1];
            } else if (i[2] == 1) {
                ++v[i[0]];
                --v[i[1]+1];
            }
            // for (auto i : v) {
            //     cout << i << " ";
            // }
            // cout << "\n";
        }
        auto sum{0};
        for (auto i = 0; i < s.size(); ++i) {
            // cout << v[i] << " ";
            sum = (sum + v[i]) % 26;
            s[i] = 'a' + (((s[i] - 'a' + sum) + 26) % 26);
            // cout << sum << " " << (s[i] - 'a' + sum) << " " << ((s[i] - 'a' + sum) % 26) << "\n";
        }
        // cout << "\n";
        return s;
    }
};
// "xuwdbdqik"
// [[4,8,0],[4,4,0],[2,4,0],[2,4,0],[6,7,1],[2,2,1],[0,2,1],[8,8,0],[1,3,1]]
// "aaa"
// [[0,2,0],[0,2,0]]