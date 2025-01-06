class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; ++i) {
            if (boxes[i] == '1') {
                for (int j = 0; i + j < n || i - j >= 0; ++j) {
                    if (i + j < n) ans[i + j] += j;
                    if (i - j >= 0) ans[i - j] += j;
                }
            }
        }
        return ans;
    }
};