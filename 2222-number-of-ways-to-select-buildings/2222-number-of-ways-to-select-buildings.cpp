class Solution {
public:
    // we either select 010 or 101
    // fix middle, find left and right options
    long long numberOfWays(string s) {
        int n = s.size();
        // index i shows the number of zeroes to the left of this index
        // if leftZero[i] = k, means that there are i-1-k ones to the left of this index
        // similar reasoning for right
        vector<int> leftZero(n, 0);
        vector<int> rightZero(n, 0);
        vector<int> leftOne(n, 0);
        vector<int> rightOne(n, 0);
        int zero = 0;
        int one = 0;
        for (int i = 0; i < n; ++i) {
            if (i >= 1) {
                leftZero[i] = zero;
                leftOne[i] = one;
            }
            if (s[i] == '0') ++zero;
            else ++one;
        }
        zero = 0;
        one = 0;
        for (int i = n-1; i >= 0; --i) {
            if (i + 1 < n) {
                rightZero[i] = zero;
                rightOne[i] = one;
            }
            if (s[i] == '0') ++zero;
            else ++one;
        }
        // for (auto i : leftZero) cout << i << " ";
        // cout << "\n";
        // for (auto i : rightZero) cout << i << " ";
        // cout << "\n";
        // for (auto i : leftOne) cout << i << " ";
        // cout << "\n";
        // for (auto i : rightOne) cout << i << " ";
        // cout << "\n";
        long long ans = 0;
        for (int i = 1; i < n-1; ++i) {
            if (s[i] == '0') {
                ans += (long long) (leftOne[i]) * (rightOne[i]);                
            } else {
                ans += (long long) (leftZero[i]) * (rightZero[i]);
            }
        }
        return ans;
    }
};