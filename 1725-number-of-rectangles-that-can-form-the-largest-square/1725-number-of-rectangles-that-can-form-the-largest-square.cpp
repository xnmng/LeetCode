class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        unordered_map<int,int> mp;
        auto maximum{0};
        for (auto i : rectangles) {
            ++mp[min(i[0], i[1])];
            maximum = max(maximum, min(i[0], i[1]));
        }
        return mp[maximum];
    }
};