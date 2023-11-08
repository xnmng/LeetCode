class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int diffx = abs(sx - fx);
        int diffy = abs(sy - fy);
        // cout << diffx << " " << diffy << "\n";
        if (diffx == 0 && diffy == 0) return t != 1; // 0 true, 1 false, >= 2 true
        if (diffy > t || diffx > t) return false;
        return true;
    }
};
// 1
// 2
// 1
// 2
// 1
// 1
// 2
// 1
// 2
// 1
// 1
// 1
// 1
// 1
// 3