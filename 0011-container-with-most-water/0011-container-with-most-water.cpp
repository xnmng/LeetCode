class Solution {
public:
    int maxArea(vector<int>& height) {
        auto ans{0};
        auto left{0};
        auto right{static_cast<int>(height.size()-1)};
        while (left < right) {
            ans = max(ans, static_cast<int>(min(height[left], height[right]) * (right - left)));
            // cout << left << " " << right << " " << static_cast<int>(min(height[left], height[right]) * (right - left)) << "\n";
            height[left] > height[right] ? --right : ++left;
        }
        return ans;
    }
};