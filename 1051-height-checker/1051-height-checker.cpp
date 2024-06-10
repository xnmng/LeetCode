class Solution {
public:
    // quicksort/mergesort/counting sort
    int heightChecker(vector<int>& heights) {
        vector<int> cpy = heights;
        sort(cpy.begin(), cpy.end());
        int n = heights.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (heights[i] != cpy[i]) ++ans;
        }
        return ans;
    }
};