class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        
        if (max(ax2, bx2) - min(ax1, bx1) < ((bx2 - bx1) + (ax2 - ax1)) &&
            max(ay2, by2) - min(ay1, by1) < ((by2 - by1) + (ay2 - ay1))) {
            // cout << "has intersect \n";
            return (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1)
                - (min(ax2, bx2) - max(ax1, bx1)) * (min(ay2, by2) - max(ay1, by1));
        }
        return (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1);
    }
};

// -2
// -2
// 2
// 2
// -1
// 4
// 1
// 6