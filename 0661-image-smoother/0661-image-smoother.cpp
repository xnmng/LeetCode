// https://youtu.be/xa83GG1RIOY?si=3FPp879qyYRCwP2K
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        /*
        since img[i][j] is at most 255, use the other bits to store answer, 
        reducing linear to constant space
        */
        int m = img.size();
        int n = img[0].size();
        int sum;
        int count;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                sum = 0;
                count = 0;
                for (int x = i-1; x <= i+1; ++x) {
                    for (int y = j-1; y <= j+1; ++y) {
                        if (x < 0 || x >= m || y < 0 || y >= n) continue;
                        ++count;
                        sum += img[x][y] % 256;
                    }
                }
                // store result in next 8 bits
                img[i][j] += sum / count * 256;
            }
        }
        // bit shift right everything to obtain result
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                img[i][j] /= 256;
            }
        }
        return img;
    }
};