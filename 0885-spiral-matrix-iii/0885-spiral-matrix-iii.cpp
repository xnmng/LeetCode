class Solution {
public:
    // simulate the process
    // O(max(rows, cols)^2) time, O(rows * cols) space
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<pair<int,int>> dir {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };
        int dirIndex = 0;
        int x = rStart;
        int y = cStart;
        int step = 1;
        bool updateStep = false;
        vector<vector<int>> ans;
        ans.reserve(rows * cols);
        while (ans.size() != rows * cols) {
            for (int i = 0; i < step; ++i) {
                if (isValid(x, y, rows, cols)) {
                    ans.emplace_back(vector<int>{x, y});
                }
                x += dir[dirIndex].first;
                y += dir[dirIndex].second;
            }
            dirIndex = (dirIndex + 1) % 4;
            if (updateStep) {
                updateStep = false;
                ++step;
            } else updateStep = true;
        }
        return ans;
    }
    
    bool isValid(int x, int y, int rows, int cols) {
        return x < rows && x >= 0 && y < cols && y >= 0;
    }
};