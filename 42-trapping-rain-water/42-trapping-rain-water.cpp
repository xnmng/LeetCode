class Solution {
public:
    int trap(vector<int>& height) {
        auto n{static_cast<int>(height.size())};
        auto ans{0};
        
        vector<int> maxLeft(height.size(), 0);
        vector<int> maxRight(height.size(), 0);

        for (auto i = n-2; i >= 0; --i) {
            maxRight[i] = max(maxRight[i+1], height[i+1]);            
        }
        for (auto i = 1; i < height.size(); ++i) {
            maxLeft[i] = max(maxLeft[i-1], height[i-1]);
            ans += max(0, min(maxLeft[i], maxRight[i]) - height[i]);
        }
        return ans;
    }
};