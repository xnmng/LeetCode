class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans = 0;
        int cur = 0;
        int temp = 0;
        for (auto& i : dimensions) {
            temp = i[0] * i[0] + i[1] * i[1];
            if (temp >= cur) {
                cur = temp;
                ans = max(ans, i[0] * i[1]);
            }
        }
        return ans;
    }
};