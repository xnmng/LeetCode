class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> s1Even(26,0);
        vector<int> s2Even(26,0);
        vector<int> s1Odd(26,0);
        vector<int> s2Odd(26,0);
        int n = s1.size();
        for (auto i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                ++s1Even[s1[i] - 'a'];
                ++s2Even[s2[i] - 'a'];
            } else {
                ++s1Odd[s1[i] - 'a'];
                ++s2Odd[s2[i] - 'a'];                
            }
        }
        // for (auto i : s1Even) cout << i << " ";
        // cout << "\n";
        // for (auto i : s2Even) cout << i << " ";
        // cout << "\n";
        // for (auto i : s1Odd) cout << i << " ";
        // cout << "\n";
        // for (auto i : s2Odd) cout << i << " ";
        // cout << "\n";
        return (s1Even == s2Even) && (s1Odd == s2Odd);
    }
};

// "kvwdssgl"
// "wskxsdgv"