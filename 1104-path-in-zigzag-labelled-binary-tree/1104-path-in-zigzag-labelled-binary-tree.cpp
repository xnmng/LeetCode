// https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/discuss/324011/Python-O(logn)-time-and-space-with-readable-code-and-step-by-step-explanation

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        auto mini{1};
        while (mini * 2 <= label) {
            mini *= 2;
        }
        auto maxi{mini * 2 - 1};
        // cout << mini << " " << maxi << "\n";
        vector<int> ans;
        while (true) {
            ans.push_back(label);
            if (label == 1) break;
            label = (maxi + mini - label) / 2;
            maxi /= 2;
            mini /= 2;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// 16