class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        vector<int> ans{0,0};
        int diff = 0;
        unordered_set<int> s1;
        unordered_set<int> s2;
        for (int i = 0; i < aliceSizes.size(); ++i) {
            diff += aliceSizes[i];
            s1.insert(aliceSizes[i]);
        }
        for (int i = 0; i < bobSizes.size(); ++i) {
            diff -= bobSizes[i];
            s2.insert(bobSizes[i]);
        }
        diff /= 2;
        for (int i : s1) {
            if (s2.find(i - diff) != s2.end()) {
                ans[0] = i;
                ans[1] = i - diff;
            }
        }
        return ans;
    }
};
// [1,2,5]
// [2,4]